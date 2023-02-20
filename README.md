# cutes

- Criação e teste de componentes e de sistema para sistemas embarcados com arduino.

## atividades para realizar testes em sistemas embarcados

As atividades a serem realizadas são agrupadas em etapas de desenvolvimento, sendo estas: Documentação e modelagem, prototipagem eletrônica, codificação e análise, conforme apresentadas na Figura a seguir. 

 - A primeira atividade de um projeto consiste em elicitar e documentar os requisitos funcionais e não funcionais, assim como os componentes, em um diagrama de requisitos da SysADL;
 - Seguindo a criação do statechart no Yakindu Statechart Tool para descrever o funcionamento do sistema já realizar a análise do path deste statechart para conseguir selecionar os casos de teste que devem ser criados para garantir uma cobertura de 100% da máquina modelada;
 - A próxima atividade consiste na definição dos casos de teste no Yakindu Statechart Tool para seguir com a prototipação eletrônica utilizando o Fritizing e um laboratório que disponibilize os componentes necessários;
 - Na etapa de codificação temos a atividade de traduzir a lógica de controle do statechart para o Arduino com o framework CUTES e uma atividade para a tradução também dos casos de teste;
 - Por fim, na etapa de análise temos a aplicação dos testes unitários e dos testes de sistema para avaliar o comportamento do SE.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/metodologia-guimaraes.png" width="100%" height="100%">

## análise de consumo de memória

Para a Figura a seguir foram utilizadas as informações retornadas pela PlatformIO sobre o uso das memórias RAM e Flash do microcontrolador. Inicialmente é apresentado o consumo das memórias para a criação da lógica de controle sem o framework, seguindo com o consumo utilizando o CUTES tanto no ambiente de criação (CREATE_ENVIROMENT) como no ambiente de teste (TEST_ENVIROMENT). Para o ambiente de teste é possível analisar o consumo tanto com o AUnit e o Arduino Unit. Para todos os cenários foi utilizado o mesmo exemplo.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-memoria.png" width="70%" height="70%">

## outros tópicos

### [arquitetura do CUTES](https://github.com/guimaraaes/cutes/tree/main/Cutes)

### [exemplos de aplicação](https://github.com/guimaraaes/cutes/tree/main/examples-platformIO)

### :mailbox: Dúvidas? Me manda um [e-mail](sguimaraaes@gmail.com)
