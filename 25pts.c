#include <stdio.h>
#include <stdlib.h>
//As funções foram definidas na ordem em que são usadas, ja que a função que esta de baixo quase sempre usa a de 
//cima no nosso codigo.
void marcarTerritorio(); //Essa função pergunta onde voce quer marcar território e leva para função dormir e/ou a função fuga.
void iniciarJogo(); //Essa função inicia o jogo, explicando a situação do personagem. O personagem é um cão. 
void jogarNovamente(); //Essa função leva para a função iniciarJogo(). Ou seja, reinicia o código.
void escolherLugar(); //Voce escolhe o lugar onde vai procurar uma saída.
void dormir(); //Nesta função voce dorme e depois vai para função escolherLugar()
void fuga(); //Esta função te leva caso escolha a opção 1 na função marcarTerritorio()
void marcarTerritorio(); //Essa função pergunta onde voce quer marcar território e leva para função dormir e/ou a função fuga.
void finalJogo(); //esta função leva ao final do jogo e reinicia o mesmo, caso queira jogar denovo.
//A função "main" chama a função iniciarJogo()

void iniciarJogo() {
    printf("Voce acabou de ser retirado das ruas, mas apenas voce, sua familia ficou pra tras, seu objetivo e fugir da casa aproveitando as oportunidades irao surgir. Boa sorte.\n");
    printf("Voce acaba de chegar em um lugar grande e fechado onde so podes ver o ceu por uns buracos.\n");
    int a;
    printf("Um humano alto e com pelo na cara tenta por a mao na sua cabeca. Desejas morde-lo?\n");
    printf("Digite 1 para sim e 0 para nao.\n");
    scanf("%d", &a);
    if (a == 1) {
        printf("Assim que voce tenta morde-lo, ele tira a mao de perto e te leva para o fundo da casa, onde podes ver o ceu.\n");
    } else if (a == 0) {
    printf("O humano faz carinho na sua cabeca e te leva pra um lugar no fundo da casa onde podes ver o ceu\n");
    }
    marcarTerritorio();
}

void jogarNovamente() {
    int outroJogo;
    printf("Voce terminou o jogo. Jogar novamente?\n");
    printf("Digite 1 para sim e 0 para nao\n");
    scanf("%d", &outroJogo);
    if(outroJogo == 1) {
        iniciarJogo();
    }   
}

void escolherLugar() {
    int localProcurar;
    printf("1: Fundos\n");
    printf("2: Porta\n");
    printf("3: Paredes em volta\n");
    printf("4: Chao\n");
    printf("Digite o numero da opcao\n");
    scanf("%d", &localProcurar);
    switch(localProcurar) {
        case 1: printf("Voce comeca a procura nos locais mais fundos da casa mas so acha algumas coisas velhas com cheiro de rato.\n");
                escolherLugar();
        case 2: printf("Voce comeca a procurar por algo perto da porta e percebe que ela nao esta fechada totalmente, e decide entrar na casa.\n");
                finalJogo();
        case 3: printf("Voce comeca a procurar envolta do quintal e não encontra nada\n");
                escolherLugar();
        case 4: printf("Voce encontra um alcapao trancado\n");
                escolherLugar();
    }
}

void dormir () {
    printf("Começa a escurecer, e voce decide ir dormir.\n");
    printf("Voce acorda e comeca a fareja novamente o lugar procurando por lugares para sair daquele lugar\n");
    printf("onde desejas olhar primeiro?\n");
    escolherLugar();
}

void fuga () {
    printf("Voce ve uma janela que leva para a rua e uma escada que leva para o 2° andar, qual pegar?\n");
    printf("Digite 1 para rua e 0 para segundo andar\n");
    int escada;
    scanf("%d", &escada);
    if (escada == 1) {
        printf("Voce olha pela janela e ve sua mulher e seus filhos passando, voce tenta latir mas eles nao te ouvem.\n");
        printf("Alguns humanos aparecem e te botam pra fora.\n");
        dormir();
    } else if (escada == 0) {
        printf("Voce sobe as escadas olha uma janela no fim da escadaria, pular por ela?\n");
        int pular;
        printf("Digite 1 para sim e 0 para nao\n");
        scanf("%d", &pular);
        if (pular == 1) {
            printf("Voce pula pela janela para tentar fugir e acaba caindo e machucando a pata quando de repente passa um caminhão e tudo fica preto...\n");
            
            jogarNovamente();
        } else if (pular == 0) {
            dormir();
        }
    }
}    

void marcarTerritorio () {
    printf("Voce comeca a cheira pelo lugar, tem varias roupas flutuando em alguns lugares com um cheiro muito forte, tem uma coisa alta e preta com um forte cheiro de queimado\n.");
    printf("Onde desejas marcar territorio?\n");
    int localMarcarTerritorio;
    printf("1: porta por onde entrou\n");
    printf("2: Coisa alta e preta\n");
    printf("3: Numa parede qualquer\n");
    printf("Digite o numero da opcao\n");
    scanf("%d", &localMarcarTerritorio);
    switch(localMarcarTerritorio) {
        case 1: 
            printf("Assim que terminas o mesmo humano entra pela porta com uma coisa na mao com um cheiro muito bom e acaba escorregando no seu xixi.\n");
            printf("Assim que ele cai ele derruba um monte de coisas no chao e voce comeca a comer e o humano volta pra dentro muito bravo.\n");
            printf("Ao cair o humano deixa a porta aberta, tentar fugir?\n");
            fuga();
            break;
        case 2: 
            printf("Assim que terminas o mesmo humano entra pela porta com uma coisa na mao com um cheiro muito bom e a coloca no chao com um pouco de agua.\n");
            dormir();
            break;
        case 3: 
            printf("Assim que terminas o mesmo humano entra pela porta com uma coisa na mao com um cheiro muito bom e a coloca no chao com um pouco de agua\n.");
            dormir();
            break;
    }
}

void finalJogo() {
    printf("Voce comeca a farejar pela casa em silencio ate que ve que a porta esta aberta, tentar fugir ou procurar mais?\n");
    int porta;
    printf("0: Fugir\n");
    printf("1: Procurar mais\n");
    printf("Escolha a opcao\n");
    scanf("%d", &porta);

    if(porta == 0) {
        printf("Voce passa pela porta e percebe um carro dando re e passa por cima de voce.\n");
        jogarNovamente();
    } else if(porta == 1) {
        printf("Voce ve outra porta, fugir por ela?\n");
        int outraPorta;
        printf("0: Nao\n");
        printf("1: Sim\n");
        printf("Escolha a opcao\n");
        scanf("%d", &outraPorta);
        if (outraPorta == 0) {
            printf("Voce acaba demorando muito e seus donos percebem e te trancam do lado de fora e voce nunca mais consegue fugir...\n");
            jogarNovamente();
        } else if (outraPorta == 1) {
            printf("Voce sai pela porta e procura por sua familia e encontra-os pouco tempo depois em um posto de gasolina.\n");
            jogarNovamente();
        }
    }
}


int main (int argc, char *argv[]) {
    iniciarJogo();

   return 0;
}