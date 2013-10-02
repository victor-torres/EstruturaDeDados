// Lista encadeada
// Victor Paiva Torres
// vpaivatorres@gmail.com

#include <iostream>

using namespace std;

class Lista
{
	private:
		int valor;
		Lista *proximoElemento;

	public:
		Lista ();
		void inserirElemento (int v);
		void inserirElementoNaPosicao (int v, int n);
		int buscarElemento (int v);
		void removerElemento (int v);
		void imprimir ();
};

Lista::Lista ()
{
	valor = 0;
	proximoElemento = NULL;
}

void Lista::inserirElemento (int v)
{
	Lista *p = this;

	while ((*p).proximoElemento != NULL)
	{
		p = (*p).proximoElemento;
	}

	(*p).proximoElemento = new Lista;
	p = (*p).proximoElemento;
	(*p).valor = v;
}

void Lista::inserirElementoNaPosicao (int v, int n)
{
	Lista *a = this;
	Lista *p = (*this).proximoElemento;

	int i = 0;

	while (i <= n && p != NULL)
	{
		if (i == n)
		{
			Lista *aux = p;
			(*a).proximoElemento = new Lista;
			p = (*a).proximoElemento;
			(*p).valor = v;
			(*p).proximoElemento = aux;
			return;
		}
		else
		{
			i++;
			a = p;
			p = (*p).proximoElemento;
		}
	}
}

int Lista::buscarElemento (int v)
{
	Lista *p = (*this).proximoElemento;

	int i = 0;

	while (p != NULL)
	{
		if ((*p).valor == v)
		{
			return i;
		}
		else
		{
			i++;
			p = (*p).proximoElemento;
		}
	}

	return -1;
}


void Lista::removerElemento (int v)
{
	Lista *a = this;
	Lista *p = (*this).proximoElemento;

	int i = 0;

	while (p != NULL)
	{
		if ((*p).valor == v)
		{
			(*a).proximoElemento = (*p).proximoElemento;
			delete p;
			return;
		}
		else
		{
			i++;
			a = p;
			p = (*p).proximoElemento;
		}
	}
}

void Lista::imprimir ()
{
	Lista *p = (*this).proximoElemento;

	while (p != NULL)
	{
		cout << (*p).valor << " ";
		p = (*p).proximoElemento;
	}

	cout << endl << endl;
}

int main ()
{
	Lista lista;

	lista.inserirElemento (1);
	lista.inserirElemento (2);
	lista.inserirElemento (3);
	lista.inserirElemento (4);
	lista.inserirElemento (5);

	cout << "Lista: ";
	lista.imprimir ();

	cout << "Adicionando 6 e 7" << endl;

	lista.inserirElemento (6);
	lista.inserirElemento (7);

	cout << "Lista: ";
	lista.imprimir ();

	cout << "Adicionando 0 a posicao 1" << endl;

	lista.inserirElementoNaPosicao (0, 0);

	cout << "Lista: ";
	lista.imprimir ();

	cout << "Adicionando 20 a posicao 3" << endl;

	lista.inserirElementoNaPosicao (20, 2);

	cout << "Lista: ";
	lista.imprimir ();

	cout << "Removendo primeira ocorrencia de 20" << endl;

	lista.removerElemento (20);

	cout << "Lista: ";
	lista.imprimir ();

	cout << "Fim de execucao" << endl;

	return 0;
}