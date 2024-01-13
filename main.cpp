#include "Atomo.hpp"

// PROTOTIPAGEM DAS FUÑÇÕES DE CONFIGURAÇÃO DOS ELETRONS
void camadaK(Eletron eletrons[], int numEle);
void camadaL(Eletron eletrons[], int numEle);
void camadaM(Eletron eletrons[], int numEle);
void camadaN(Eletron eletrons[], int numEle);
void camadaO(Eletron eletrons[], int numEle);
void camadaP(Eletron eletrons[], int numEle);
void camadaQ(Eletron eletrons[], int numEle);


char ultimaCamada;                                  //Variável responsável pela adaptação dos ângulos na camada de valência
int verificaNumCam(int ele);                        //Verifica qual é a camada de valência
int camBohr[7] = { 2, 8, 18, 32, 32, 18, 8 };       //Array com número total de eletrons possíveis em cada camada
    


int main()
{
    //CRIAÇÃO DA JANELA E BACKGROUND
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Modelo Ultra Realístico de um Átomo", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(Background);
    sf::Sprite sprite(backgroundTexture);
  

    //NÚCLEO
    Nucleo nucleo(window.getSize().x - 70, window.getSize().y - 60);



    //ELETRONS
    int numEletrons = 21;

    switch (verificaNumCam(numEletrons))                //Verifica quantas camadas de eletrons existe e 'traduz' para um tipo char.
    {
    case 1:
        ultimaCamada = 'K';
        break;
    case 2:
        ultimaCamada = 'L';
        break;
    case 3:
        ultimaCamada = 'M';
        break;
    case 4:
        ultimaCamada = 'N';
        break;
    case 5:
        ultimaCamada = 'O';
        break;
    case 6:
        ultimaCamada = 'P';
        break;
    case 7:
        ultimaCamada = 'Q';
        break;
    }


    Eletron eletrons[118];                              //Instanciação de todos os eletrons possíveis
    
    camadaK(eletrons, numEletrons);                     //Configura os eletrons da camada K
    camadaL(eletrons, numEletrons);                     //Configura os eletrons da camada L
    camadaM(eletrons, numEletrons);                     //Configura os eletrons da camada M
    camadaN(eletrons, numEletrons);                     //Configura os eletrons da camada N
    camadaO(eletrons, numEletrons);                     //Configura os eletrons da camada O
    camadaP(eletrons, numEletrons);                     //Configura os eletrons da camada P
    camadaQ(eletrons, numEletrons);                     //Configura os eletrons da camada Q

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        window.clear();
        window.draw(sprite);

        for (int i = 0; i < numEletrons; i++)
        {
            eletrons[i].updatePosition();           
        }

        for (int i = 0; i < numEletrons; i++)
        {
            eletrons[i].draw(window);              
        }
        
        nucleo.draw(window);

        window.display();
    }
    return EXIT_SUCCESS;
};

//  ================  CAMADAS ===================== //

void camadaK(Eletron eletrons[], int numEle)
{
    int camBohrK = 2;
    int aux = 1;

    if (ultimaCamada == 'K')                                    //Verifica se a camada atual é a última, caso seja, altera o número de eletrons na camada
    {                                                               
        camBohrK = numEle;
    }

    for (int i = 0; i < camBohrK; i++)
    {
        eletrons[i].radiusOrbit = 100;
        eletrons[i].angle = float(360 / camBohrK) * aux++;
        eletrons[i].speed = 3;
    }
}

void camadaL(Eletron eletrons[], int numEle)
{
    int camBohrL = 8;
    int aux = 1;

    if (ultimaCamada == 'L')                                    //Verifica se a camada atual é a última, caso seja, altera o número de eletrons na camada
    {
        camBohrL = numEle - 2;
    }

    for (int i = 2; i < 2 + camBohrL; i++)
    {
        eletrons[i].radiusOrbit = 180;
        eletrons[i].angle = float(360 / camBohrL) * aux++;
        eletrons[i].speed = 2.6;
    }
}

void camadaM(Eletron eletrons[], int numEle)
{
    int camBohrM = 18;
    int aux = 1;

    if (ultimaCamada == 'M')                                    //Verifica se a camada atual é a última, caso seja, altera o número de eletrons na camada
    {
        camBohrM = numEle - 10;
    }

    for (int i = 10; i < 10 + camBohrM; i++)
    {
        eletrons[i].radiusOrbit = 260;
        eletrons[i].angle = float((360 / camBohrM) * aux++);
        eletrons[i].speed = 2.2;
    }
}

void camadaN(Eletron eletrons[], int numEle)
{
    int camBohrN = 32;
    int aux = 1;

    if (ultimaCamada == 'N')                                    //Verifica se a camada atual é a última, caso seja, altera o número de eletrons na camada
    {
        camBohrN = numEle - 28;
    }

    for (int i = 28; i < 28 + camBohrN; i++)
    {
        eletrons[i].radiusOrbit = 340;
        eletrons[i].angle = float((360 / camBohrN) * aux++);
        eletrons[i].speed = 1.8;
    }
}

void camadaO(Eletron eletrons[], int numEle)
{
    int camBohrO = 32;
    int aux = 1;

    if (ultimaCamada == 'O')                                    //Verifica se a camada atual é a última, caso seja, altera o número de eletrons na camada
    {
        camBohrO = numEle - 60;
    }

    for(int i = 60; i < 60 + camBohrO;i++)
    {
        eletrons[i].radiusOrbit = 400;
        eletrons[i].angle = float((360 / camBohrO) * aux++);
        eletrons[i].speed = 1.4;
    }
}

void camadaP(Eletron eletrons[], int numEle)
{
    int camBohrP = 18;
    int aux = 1;

    if (ultimaCamada == 'P')                                    //Verifica se a camada atual é a última, caso seja, altera o número de eletrons na camada
    {
        camBohrP = numEle - 92;
    }

    for (int i = 92; i < 92 + camBohrP; i++)
    {
        eletrons[i].radiusOrbit = 460;
        eletrons[i].angle = float((360 / camBohrP) * aux++);
        eletrons[i].speed = 1.0;
    }
}

void camadaQ(Eletron eletrons[], int numEle)
{
    int camBohrQ = 8;
    int aux = 1;

    if (ultimaCamada == 'Q')                                    //Verifica se a camada atual é a última, caso seja, altera o número de eletrons na camada
    {
        camBohrQ = numEle - 110;
    }

    for (int i = 110; i < 110 + camBohrQ; i++)
    {
        eletrons[i].radiusOrbit = 500;
        eletrons[i].angle = float((360 / camBohrQ) * aux++);
        eletrons[i].speed = 0.6;
    }
}
        
int verificaNumCam(int ele)                                     //Função que retorna no número de camadas
{
    int numCam = 0;
    for (int i = 0; i < 7; i++)
    {
        if (ele < 0)
        {
            return numCam;
        }

        numCam++;
        ele -= camBohr[i];
    }
}