#ifndef TESTE_H
#define TESTE_H
#include <stdio.h>

using namespace std;

class teste
{
    public:
        void mostraCampo() {
            printf("ClassePai: %d\n", campo_privado);
        }

        teste(int cmp_priv) {
            campo_privado = cmp_priv;
            campo_protegido = 2*cmp_priv;
        }

    protected:
        int campo_protegido;

    private:
        int campo_privado;
};

class ClasseFilha : public teste {
public:
        void mostraCampo() {
            printf("ClasseFilha: %d\n", campo_protegido);
        }

        ClasseFilha(int cmp_priv) : teste(cmp_priv) {
            campo_protegido = 10;
        }
};


#endif // TESTE_H
