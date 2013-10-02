// Lista encadeada com nó
// Victor Paiva Torres
// vpaivatorres@gmail.com

#include <iostream>

using namespace std;


class No
{
	public:
		int valor;
		No *proximoElemento;
		No ();
};

class Lista
{
	private:
		No *primeiroElemento;
		No *ultimoElemento;
		int quantidadeDeElementos;

	public:
		Lista ();
		void inserirElemento (int v);
		void inserirElementoNaPosicao (int v, int n);
		int buscarElemento (int v);
		void removerElemento (int v);
		void imprimir ();
};

No::No ()
{
	valor = 0;
	proximoElemento = NULL;
}

Lista::Lista ()
{
	primeiroElemento = NULL;
	ultimoElemento = NULL;
	quantidadeDeElementos = 0;
}

void Lista::inserirElemento (int v)
{
	No *elemento = NULL;
	elemento = new No;

	if (quantidadeDeElementos == 0)
	{
		primeiroElemento = elemento;
	}
	else
	{
		(*ultimoElemento).proximoElemento = elemento;
	}
	
	ultimoElemento = elemento;
	quantidadeDeElementos++;

	(*elemento).valor = v;
}

void Lista::inserirElementoNaPosicao (int v, int n)
{
	No *elementoAnterior = NULL;
	No *elemento = primeiroElemento;

	int i = 0;

	while (i <= n && elemento != NULL)
	{
		if (i == n)
		{
			No *aux = new No;

			if (elementoAnterior == NULL)
			{
				primeiroElemento = aux;
			}
			else
			{
				(*elementoAnterior).proximoElemento = aux;
			}

			(*aux).valor = v;
			(*aux).proximoElemento = elemento;
			ultimoElemento = elemento;
			quantidadeDeElementos++;

			return;
		}
		else
		{
			elementoAnterior = elemento;
			elemento = (*elemento).proximoElemento;
			i++;
		}
	}
}

int Lista::buscarElemento (int v)
{
	No *elemento = primeiroElemento;

	int i = 0;

	while (elemento != NULL)
	{
		if ((*elemento).valor == v)
		{
			return i;
		}
		else
		{
			elemento = (*elemento).proximoElemento;
			i++;
		}
	}

	return -1;
}


void Lista::removerElemento (int v)
{
	No *elementoAnterior = NULL;
	No *elemento = primeiroElemento;

	int i = 0;

	while (elemento != NULL)
	{
		if ((*elemento).valor == v)
		{
			(*elementoAnterior).proximoElemento = (*elemento).proximoElemento;
			delete elemento;
			quantidadeDeElementos--;
			return;
		}
		else
		{
			elementoAnterior = elemento;
			elemento = (*elemento).proximoElemento;
			i++;
		}
	}
}

void Lista::imprimir ()
{
	No *elemento = primeiroElemento;

	while (elemento != NULL)
	{
		cout << (*elemento).valor << " ";
		elemento = (*elemento).proximoElemento;
	}

	cout << "{ " << quantidadeDeElementos << " elementos }" << endl << endl;
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
	
	cout << "Buscando indice do elemento 20" << endl;

	cout << "O elemento 20 esta na posicao ";
	cout << lista.buscarElemento(20) + 1 << endl << endl; 

	cout << "Removendo primeira ocorrencia de 20" << endl;

	lista.removerElemento (20);

	cout << "Lista: ";
	lista.imprimir ();

	cout << "Fim de execucao" << endl;

	return 0;
}
