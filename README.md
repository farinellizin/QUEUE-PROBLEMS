<h1 align = "center">
  <strong><em>Aplicação de Filas Dinâmicas e Lineares</em></strong>
</h1>

<h4 align = "center">
  Este repositório contém aplicações práticas relacionada ao contéudo teórico de Filas Dinâmicas e Lineares, lecionadas na matéria Algoritmo e Estrutura 
  de Dados I.
</h4>

<h2 align="center"><em> Objetivo </em></h2>

<h4 align="center">
  Por meio desta atividade, busca-se compreender e estar apto a manipular o funcionamento de Filas Dinâmicas e Lineares, verificando o sucesso do processo por meio da implementação do que se é pedido.
</h4>

<h2 align="center"> <strong><em>Proposta</em></strong> </h2>

<i>
  <h3>
    Uma estrutura baseada em fila tem por definição a regra de sempre remover do início e inserir novos elementos no final. Sabendo-se disso, vamos praticar a utilização desse conceito nos seguintes problemas:
  </h3>

  <ol type="I">
    <li>
      Escreva uma função que receba pares de filas, ambas de tanho n, divida ambas ao meio e ligue as metadas para compor duas novas filas, as quais devem ser retornadas para o usuário. Tais filas devem ser definidas como dinâmicas.
    </li>
    <li>
      Escreva uma função que aplica uma equação matemática qualquer aos numeros de uma ˜ fila. Essa equação tem por objetivo produzir um indexador para a fila dada como entrada, logo, precisa ser retornado junto com a fila para o usuário.
    </li>
     <li>
    Elabore uma função que receba um conjunto de filas, todas com valores de indexação conforme item (b). Ordene esse grupo de filas pelo método da bolha e as retorne ao usuário considerando o maior valor de indexação como cabeça dessa ordem.
   </li>
  </ol>
</i>


<h2 align="center">Resoluções detalhadas</h2>

<h2>Aplicação 1</h2>

Recapitulando o que a primeira aplicação propôe, é pedido uma função que receberá duas **Filas**, com o mesmo tamanho. Na sequência, ambas as filas serão divididas ao meio, conectando as opostas de uma a outra. Isto é, a primeira metade da primeira, com a segunda metade da segunda - a primeira metade da segunda, com a segunda metade da primeira.

### Implementação

Inicialmente, foram feitas duas **Filas** vazias, a fim de possibilitar a manipulação das mesmas, por meio da função **FFVazia()**: 

```c++
void FFVazia(Fila *f){
	f -> first = (Block*) malloc (sizeof(Block));
	f -> last  = f -> first;
	f -> first -> prox = NULL;
}
```

Na sequência, faz-se necessário definir o tamanho de tais **Filas**. Para isso, foi utilizada a função **define_queue_size()**, a qual utiliza da função **rand()** para obter um número aleatório dentro do intervalo desejado:

```c++
int define_queue_size() {
    srand(time(NULL));

    int size = rand() % 15 + 2;
    return size;
}
```

Seguindo, é preciso agora preencher essas **Filas** com inteiros aleatórios. A fim de realpizar tal processo, foi utilizada a função **fill_queue()**:

```c++
void fill_queue(Fila *queue, int size) {
    Item aux;
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        aux.val = rand () % 100 + 1;
        Enfileira(queue, aux);
    }
}
```

Tendo ambas as **Filas** devidamente preenchidas, chega no momento de separar-lás. A fim de realizar essa separação, **Filas** auxiliares foram criadas, como pode ser visto no bloco de código abaixo: 

```c++
Fila first_half_queue_1;
FFVazia(&first_half_queue_1);

Fila first_half_queue_2;
FFVazia(&first_half_queue_2);
```

Assim, será chamada a função **break_apart_in_half()** para a **Fila** incial, passando também como parâmetro em quais **Filas** as metades serão armazenadas (auxiliares):

```c++
void break_apart_in_half(Fila *queue, Fila *first_half_queue, int size) {
    Item aux_item;
    
    for (int i = 0; i < (size / 2); i++) {
        Desenfileira(queue, &aux_item);
        Enfileira(first_half_queue, aux_item);
    }
}
```

E, em seguida, é chamada a função **pull_together_two_queues()**, para juntar as metades que acabaram de ser separadas:

```c++
void pull_together_two_queues(Fila *queue_first_half, Fila *queue_second_half, Fila *final_queue) {
    Item aux;
    while (!queue_is_empty(queue_first_half)) {
        Desenfileira(queue_first_half, &aux);
        Enfileira(final_queue, aux);
    }
    
    while(!queue_is_empty(queue_second_half)) {
        Desenfileira(queue_second_half, &aux);
        Enfileira(final_queue, aux);
    }

    cout << endl << endl << "\t";
    FImprime(final_queue);
}
```

Sendo o processo repetido igualmente para as duas **Filas**, armazenando a **Fila** final em uma nova **FIla**:

```c++
Fila final_queue_1;
FFVazia(&final_queue_1);
pull_together_two_queues(&first_half_queue_1, &queue_2, &final_queue_1);

Fila final_queue_2;
FFVazia(&final_queue_2);
pull_together_two_queues(&first_half_queue_2, &queue_1, &final_queue_2);
```

<h2>Aplicação 2</h2>

Recapitulando o que o exercício propõe, ele nos pede que aplique uma equação matemática qualquer aos números inseridos em uma fila, e essa equação tem por objetivo criar um indexador e salvá-lo na mesma fila. Foi escolhido por nós, aplicar a equação matemática de média aritmética dos elementos da fila e o armazenamento do indexador produzido por esse cálculo, será na última posição da fila.


  <h3>Implementação</h3>
  
  Inicialmente foi criada uma função para que o usuário insira quantos valores ele desejar nesta fila. Exemplo da função abaixo:
  
  ```c++
    void insertNewValue(Fila *f, Item d){
	int aux, opt = -1;

	while(opt != 0){
		if(opt == 1){
			cout << "Valor inserido com sucesso." << endl << endl;
		}

		cout << "Digite 1 se deseja adicionar um novo valor a fila." << endl;
		cout << "Digite 0 se não deseja adicionar mais nenhum valor a fila." << endl << endl;

		cout << "Opção: ";
		cin >> opt;
		cout << endl;

		if(opt == 1){
			cout << "Insira o valor que deseja adicionar a fila: ";
			cin >> aux;

			d.val = aux;
			Enfileira(f, d);

			cout << endl;
		}

		else if(opt == 0){
			cout << "Saindo da função de inserção de novos valores a fila..." << endl << endl;
		}

		else{
			cout << "Opção inválida." << endl << endl;
		}

		system("clear");
	}
}
  ```
  
  Logo após o usuário finalizar esta função, saindo do looping e selecionando a opção de saída, o código irá para a função que fará o cálculo da média aritmética dos elementos desta lista. Exemplo do código da função abaixo:
  
  ```c++
    void equation(Fila *f, Item d){
	Block *aux;
	int sum = 0, cont = 0;
	int average;

	aux = f->first->prox;

	while(aux != NULL){
		sum += aux->data.val;
		cont += 1;

		aux = aux->prox;
	}

	average = sum/cont;

	d.val = average;
	Enfileira(f, d);

	cout << endl << "O resultado da equação de média aritmética aplicada a essa fila, desconsiderando casas decimais, é igual a: " << average << endl << endl;
}
  ```
  
  A função irá percorrer toda a lista executando a soma dos elementos e fazendo a contagem de quantos elementos possui, ao final disso, irá dividir a soma dos elementos pela contagem de elementos que a lista possui e armazenar esse valor em uma variável, usando esta variável, será feita a inserção da média aritmética ao final da fila e será impresso o valor da média aritmética.

<h2>Aplicação 3</h2>

Recapitulando o que o exercício propõe, nos é pedido a eloboração de uma função que receba um conjunto de filas, todas que contenham o valor de indexação, como na <strong>Aplicação 2</strong>, e que seja ordenado esse conjunto de filas pelo método da bolha e as retorne ao usuário considerando o maior valor de indexação como cabeça dessa ordem.

Foram escolhidos um conjunto de 3 filas para fazer a implementação deste código, podendo ser aumentado esse conjunto alterando o arquivo <code>main.cpp</code> caso seja desejado.

  <h3>Implementação</h3>
  
  Como na <strong>Aplicação 2</strong>, foram usadas a função <code>void insertNewValue</code> para o usuário inserir quantos números ele deseja nas listas, sendo seguido desta vez (Após encerrar a inserção de elementos em uma lista, ele já vai para a próxima), a função <code>equation</code> mas agora com algumas alterações que vamos descrever abaixo.

Foi criada uma nova função neste código, chamada de <code>descendingSort</code>, que serve para ordenar a fila que contém os indexadores em ordem decrescente. Exemplo da função abaixo:

```c++
  void descendingSort(Fila *Index){
	Block *i, *j;

	i = Index->first->prox;

	while(i != NULL){
		j = i->prox;

		while(j != NULL){
			if(j->data.val > i->data.val){
				Swap(i, j);
			}

			j = j->prox;
		}

		i = i->prox;
	}
}
```

Agora voltando para a função <code>equation</code>, é possível analisar duas alterações, que são nada mais nada menos que duas linhas de código ao final da função, uma enfilerando o indexador na fila criada para armazenar indexadores e outra chamando a função <code>descendingSort</code> para ordenar essa fila de indexadores. Exemplo abaixo:

```c++
  void equation(Fila *Index, Fila *f, Item d){
	Block *aux;
	int sum = 0, cont = 0;
	int average;

	aux = f->first->prox;

	while(aux != NULL){
		sum += aux->data.val;
		cont += 1;

		aux = aux->prox;
	}

	average = sum/cont;

	d.val = average;
	Enfileira(f, d);
	Enfileira(Index, d);

	descendingSort(Index);

	cout << endl << "O resultado da equação de média aritmética aplicada a essa fila, desconsiderando casas decimais, é igual a: " << average << endl << endl;
}
```

Após percorrer todo o código, será impresso a fila dos indexadores em ordem descrescente, como pedido no exercício.

<h2 align="center">Compilação e Execução</h2>

O repositório possui um arquivo <i>Makefile</i> que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<table align="center">
  <tr>
    <td><strong>Comando</strong></td>
    <td><strong>Função</strong></td>
  </tr>
  <tr>
    <td><code>make clean</code></td>
    <td>Apaga a última compilação realizada contida na pasta build.</td>
  </tr>
  <tr>
    <td><code>make</code></td>
    <td>Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.</td>
  </tr>
  <tr>
    <td><code>make run</code></td>
    <td>Executa o programa da pasta build após a realização da compilação.</td>
  </tr>
</table>
    
## Alunos
- Lucas Farinelli
- Felipe Campos
- Caio Dias
- João Marcelo
