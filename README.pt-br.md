# A fundo na linguagem C.

[Leia em Ingles](README.md)

**Objetivo:** Mostrar meus conhecimentos da linguagem C e suas caracteristicas.

Esse projeto mostra um conjunto das minhas proprias implementacoes de bibliotecas e algoritmos, buscando entender como as coisas funcionam por de baixo dos panos.

## Como rodar

Você pode compilar o projeto usando `gcc`:

```bash
gcc main.c -I./include -o main.out
./main.out
```

## Funções

### String Utils

*my_strlen*: 
    - Args: char array (String).
    - Return: integer (String lenght).
    - Process: 
        Eu começo declarando uma variável `lenght` fora do loop para evitar que ela seja resetada. Um loop `while` foi escolhido porque eu prefiro trabalhar com aritmética de ponteiros. (Mas um loop `for` com uma variável de controle `i` também poderia ser usado).
        Dentro do loop `while`, incrementamos tanto o contador `length` quanto o próprio ponteiro. Como `*str` começa apontando para o primeiro elemento (`str[0]`), incrementar o ponteiro nos permite percorrer cada endereço de memória até atingirmos o `\0` que tem valor 0 (`false`). Finalmente, retornamos o comprimento.

*my_tolower:
    - Args: char array (String).
    - Return: char array (String).
    - Process:
        Começo declarando a variável que vai servir para definir o tamanho da string (utilizando a função anteriormente criada) e alocando uma nova string com malloc. Apesar de caracteres sempre serem 1 byte, optei por deixar explícito o sizeof(char) para melhor leitura. Em seguida, garanto que houve sucesso na alocação (caso contrário, a função retorna NULL). Depois, declaro o ponteiro *ptr, que servirá como cursor, enquanto o *new_string funcionará como âncora. Após isso, defino a distância entre 'a' e 'A' para facilitar a conversão, visto que esse valor é constante na tabela ASCII. Começo então o loop while, escolhido para trabalharmos com aritmética de ponteiros. O primeiro passo da conversão é saber se o elemento da *str está em maiúsculo; para isso, basta conferirmos se ele está dentro do intervalo ['A', 'Z'] (que o compilador entenderá como inteiros devido à codificação ASCII). Se estiver, defino que o ponteiro cursor *ptr receberá o valor de *str somado à distância calculada, convertendo o caractere para minúsculo. Em seguida, incremento o ponteiro cursor e o array base para avançarmos para o próximo caractere em ambos. Não fazemos esse incremento no *new_string, pois precisamos que este ponteiro continue apontando para o primeiro elemento do array para o retorno final. Caso o caractere já seja minúsculo ou um símbolo, o *ptr apenas recebe o valor original de *str. Para finalizar, apontamos o último elemento de *ptr como sendo o terminador nulo \0 e retornamos a new_str.
        
        


### Math Utils
(Em breve...)
