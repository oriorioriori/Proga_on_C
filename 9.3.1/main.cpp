#include <iostream>
#include <fstream>
using namespace std;

/*

В файле задаются комплексные числа в таком виде: <действительная часть> <мнимая часть>

*/

struct Complex
{
    float a, b;

    Complex();
    Complex(float, float);

    Complex mul(Complex);
    Complex div(Complex);
    Complex sum(Complex);
    Complex sub(Complex);
};

struct Matrix
{

    int m_size;
    Complex** mat;

    Matrix(int);
    ~Matrix();

    Complex determinant();
    Matrix* transpose();
    Matrix* sub(Matrix&);
    Matrix* mul(Matrix&);
    Matrix* mul(Complex);

};

Complex::Complex(float a, float b)
{
    this->a = a;
    this->b = b;
}

Complex::Complex()
{
    this->a = 0;
    this->b = 0;
}

Complex Complex::mul(Complex c)
{
    float aa = a * c.a - b * c.b;
    float bb = a * c.b + b * c.a;

    Complex result(aa, bb);

    return result;
}

Complex Complex::div(Complex c)
{
    float aa = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
    float bb = (a * c.b - a * c.a) / (c.a * c.a + c.b * c.b);

    Complex result(aa, bb);

    return result;
}

Complex Complex::sum(Complex c)
{
    float aa = a + c.a;
    float bb = b + c.b;

    Complex result(aa, bb);

    return result;
}

Complex Complex::sub(Complex c)
{
    float aa = a - c.a;
    float bb = b - c.b;

    Complex result(aa, bb);

    return result;
}

Matrix::Matrix(int m_size)
{

    this->m_size = m_size;

    mat = new Complex*[m_size];
    for (int i = 0; i < m_size; i++)
    {
        mat[i] = new Complex[m_size];
    }

}

Matrix::~Matrix()
{
    for (int i = 0; i < m_size; i++)
        delete [] mat[i];

    delete [] mat;
}

Complex Matrix::determinant()
{

    if (m_size == 1)
        return mat[0][0];

    Complex result(0, 0);

    for (int i = 0; i < m_size; i++)
    {

        Matrix minor(m_size - 1);

        for (int j = 1; j < m_size; j++)
            for (int k = 0; k < m_size; k++)
            {
                if (k == i)
                    continue;

                minor.mat[j - 1][(k <= i)?k:(k - 1)] = mat[j][k];
            }

        if (i % 2)
            result = result.sub(mat[0][i].mul(minor.determinant()));
        else
            result = result.sum(mat[0][i].mul(minor.determinant()));

    }

    return result;

}

Matrix* Matrix::transpose()
{

    Matrix* result = new Matrix(m_size);

    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            result->mat[i][j] = mat[j][i];

    return result;

}

Matrix* Matrix::sub(Matrix& m)
{

    Matrix* result = new Matrix(m_size);

    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            result->mat[i][j] = mat[i][j].sub(m.mat[i][j]);

    return result;

}

Matrix* Matrix::mul(Matrix& m)
{

    if (m_size != m.m_size)
        return 0;

    Matrix* result = new Matrix(m_size);

    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            for (int k = 0; k < m_size; k++)
                result->mat[i][j] = result->mat[i][j].sum(mat[i][k].mul(m.mat[k][j]));

    return result;

}

Matrix* Matrix::mul(Complex c)
{

    Matrix* result = new Matrix(m_size);

    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            result->mat[i][j] = mat[i][j].mul(c);

    return result;

}

void read_complex(ifstream& input, Complex& c)
{

    float a;
    input >> a;

    float b;
    input >> b;

    c.a = a;
    c.b = b;

}

void read_matrix(ifstream& input, Matrix& m)
{

    for (int i = 0; i < m.m_size; i++)
        for (int j = 0; j < m.m_size; j++)
            read_complex(input, m.mat[i][j]);

}

int main()
{

    ifstream input("test.txt");

    Complex a(0, 0);
    read_complex(input, a);

    Complex b(0, 0);
    read_complex(input, b);

    Complex c(0, 0);
    read_complex(input, c);

    Complex result = a.mul(b).mul(b).mul(b).sub(c).div(a.sum(b));

    cout << "(a * b^3 - c)/(a + b) = " << result.a << " + " << result.b << "*i\n\n";

    int a_size;
    int b_size;

    input >> a_size;
    Matrix am(a_size);
    read_matrix(input, am);

    input >> b_size;
    Matrix bm(b_size);
    read_matrix(input, bm);

    Matrix* result_matrix = (am.mul(bm.determinant())->sub(*am.transpose()))->mul(am);

    if (result_matrix == 0) /*выражение таково, что это уловие невыполнимо, но если поменять выражение, что бы было умножение A*B, то может выполниться, лучше оставить*/
    {
        cout << "Multiplication error :( (Matrix sizes are not equal to each other)";

        cin.get();

        return -1;
    }

    cout << "(det(B) * A - A^(T)) * A:\n";

    for (int i = 0; i < result_matrix->m_size; i++)
    {
        for (int j = 0; j < result_matrix->m_size; j++)
            cout << result_matrix->mat[i][j].a << "+" << result_matrix->mat[i][j].b << "*i\t";

        cout << "\n";
    }

    cin.get();

    return 0;
}
