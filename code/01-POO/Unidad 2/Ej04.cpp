#include <iostream>

using namespace std;

class VectorDinamico {
private:
    uint m_size;
    int *m_data;

public:
    VectorDinamico(uint s) {
        m_size = s;
        m_data = new int[m_size];
        for (int i=0; i<m_size; ++i) {
            m_data[i] = rand()%51;
        }
    }
    VectorDinamico(const VectorDinamico &v) {
        m_size = v.m_size;
        m_data = new int[m_size];

        for (int i=0; i<m_size; ++i) {
            m_data[i] = v.m_data[i];
        }
    }
    ~VectorDinamico() { delete [] m_data; };
    
    void Duplicar() {
        m_size *= 2;
        int *a = new int[m_size];
        for (int i=0; i<m_size; ++i) {
            if (i<m_size/2) { 
                a[i] = m_data[i]; 
            } else {
                a[i] = rand()%51;
            }
        }
        delete [] m_data;
        m_data = a;
        a = nullptr;
    }
    int VerElemento(uint i) { return m_data[i]; }
    int Size() { return m_size; }
};

int main() {
    VectorDinamico v1(4);

    for (int i=0; i<v1.Size(); ++i) {
        cout << v1.VerElemento(i) << " ";
    }
    cout << endl;

    v1.Duplicar();

    for (int i=0; i<v1.Size(); ++i) {
        cout << v1.VerElemento(i) << " ";
    }
    cout << endl;

    return 0;
}