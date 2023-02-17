# cutes

- Creation and testing of units and integration for components of embedded systems with arduino

## atividades para realizar testes em sistemas embarcados

- A primeira atividade de um projeto consiste em:

  - elicitar e documentar os requisitos funcionais e não funcionais, assim como os componentes, em um diagrama de requisitos da SysADL.
  - Seguindo com um conjunto de atividades com a ferramenta Yakindu Statechart Tool para modelar o funcionamento do sistema em statechart;
  - e definir os casos de testes que garantam cobertura de 100% da máquina modelada.

- O próximo conjunto de atividades é destinado para a criação do SE:
  - a prototipação eletrônica utilizando o Fritizing e um laboratório que disponibilize os componentes necessários seguindo com a atividade de definir a lógica de controle para o arduino com o CUTES.
  - Na atividade de teste os casos de testes do Yakindu Statechart Tool são traduzidos para C++ com o CUTES.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-atividades.png" width="100%" height="100%">

## análise de consumo de memória

Para a Figura a seguir foram utilizadas as informações retornadas pela PlatformIO sobre o uso das memórias RAM e Flash do microcontrolador. Inicialmente é apresentado o consumo das memórias para a criação da lógica de controle sem o framework, seguindo com o consumo utilizando o CUTES tanto no ambiente de criação (CREATE_ENVIROMENT) como no ambiente de teste (TEST_ENVIROMENT). Para o ambiente de teste é possível analisar o consumo tanto com o AUnit e o Arduino Unit. Para todos os cenários foi utilizado o mesmo exemplo.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-memoria.png" width="70%" height="70%">

## outros tópicos

### [arquitetura do CUTES](https://github.com/guimaraaes/cutes/tree/main/cutes)

### [exemplos de aplicação](https://github.com/guimaraaes/cutes/tree/main/examples-platformIO)

### :mailbox: Dúvidas? Me manda um [e-mail](sguimaraaes@gmail.com)
