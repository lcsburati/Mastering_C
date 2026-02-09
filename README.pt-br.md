# A fundo na linguagem C.

[Leia em Inglês](README.md)

**Objetivo:** Mostrar meus conhecimentos da linguagem C e suas características.

Esse projeto mostra um conjunto das minhas próprias implementações de bibliotecas e algoritmos, buscando entender como as coisas funcionam por baixo dos panos.

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
    - Return: integer (String length).
    - Process: 
        Eu começo declarando uma variável `length` fora do loop para evitar que ela seja resetada. Um loop `while` foi escolhido porque eu prefiro trabalhar com aritmética de ponteiros. (Mas um loop `for` com uma variável de controle `i` também poderia ser usado).
        Dentro do loop `while`, incrementamos tanto o contador `length` quanto o próprio ponteiro. Como `*str` começa apontando para o primeiro elemento (`str[0]`), incrementar o ponteiro nos permite percorrer cada endereço de memória até atingirmos o `\0` que tem valor 0 (`false`). Finalmente, retornamos o comprimento.

*my_tolower*:
    - Args: char array (String).
    - Return: char array (String).
    - Process:
        Começo declarando a variável que vai servir para definir o tamanho da string (utilizando a função anteriormente criada) e alocando uma nova string com `malloc`. Apesar de caracteres serem sempre 1 byte, optei por deixar explícito o `sizeof(char)` para melhor leitura. Em seguida, garanto que houve sucesso na alocação (caso contrário, a função retorna NULL). Depois, declaro o ponteiro `*ptr`, que servirá como cursor, enquanto o `*new_string` funcionará como âncora. Após isso, defino a distância entre 'a' e 'A' para facilitar a conversão, visto que esse valor é constante na tabela ASCII. Começo então o loop `while`, escolhido para trabalharmos com aritmética de ponteiros. O primeiro passo da conversão é saber se o elemento da `*str` está em maiúsculo; para isso, basta conferirmos se ele está dentro do intervalo ['A', 'Z'] (que o compilador entenderá como inteiros devido à codificação ASCII). Se estiver, defino que o ponteiro cursor `*ptr` receberá o valor de `*str` somado à distância calculada, convertendo o caractere para minúsculo. Em seguida, incremento o ponteiro cursor e o array base para avançarmos para o próximo caractere em ambos. Não fazemos esse incremento no `*new_string`, pois precisamos que este ponteiro continue apontando para o primeiro elemento do array para o retorno final. Caso o caractere já seja minúsculo ou um símbolo, o `*ptr` apenas recebe o valor original de `*str`. Para finalizar, apontamos o último elemento de `*ptr` como sendo o terminador nulo `\0` e retornamos a `new_str`.

*my_toupper*:
    - Args: char array (String).
    - Return: char array (String).
    - Process: Seguimos o mesmo processo da `my_tolower`, mudando apenas o `if (*str >= 'A' && *str <= 'Z')` para `if (*str >= 'a' && *str <= 'z')`, uma vez que agora queremos atualizar valores minúsculos.
        
        
*my_strcmp*:
    - Args: const char *st1, const char *str2
    - Return: Integer (Se as strings forem de mesmo tamanho retorna 0, se a string 2 for maior retorna 1 e se a string 1 for menor retorna -1).
    - Process: Começo declarando as variáveis que irão receber o tamanho das strings e, utilizando minha própria `my_strlen`, eu verifico o tamanho de cada string.
    Após isso, inicio a primeira camada de verificação que é sobre os tamanhos de cada string e começo o processo de verificação caractere por caractere com a mesma lógica de aritmética de ponteiros (aqui não foi necessário criar uma âncora, pois a palavra em si não seria necessária para a função).

*my_strcmp_percent*:
    - const char *st1, const char *str2
    - Return: Double (Porcentagem de igualdade entre as strings).
    - Process: Inicio declarando as variáveis necessárias (tamanho das strings e a porcentagem da diferença entre elas).
    Após isso, eu verifico o tamanho de cada uma delas para iniciar o `while` pela menor; feito isso, eu faço a verificação caractere por caractere com a mesma lógica de aritmética de ponteiros.
    A lógica utilizada para analisar a diferença entre os caracteres se baseia na distância entre cada caractere em relação ao primeiro, porém erros já foram notados nos testes e essa função provavelmente será substituída pela utilização da distância de Levenshtein futuramente.
    

### Math Utils
(Em breve...)
