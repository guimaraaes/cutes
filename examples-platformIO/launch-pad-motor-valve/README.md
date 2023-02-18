
# launch-pad-motor-valve

## Elicitar requisitos

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/launch-pad-motor-valve/assets/requisitos.png" width="80%" height="80%">

## Statechart ([acesse a documentação aqui com os casos de teste](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/launch-pad-motor-valve))

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/launch-pad-motor-valve/assets/statechart.png" width="50%" height="50%">

## Árvore de caminhos do Statechart 

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/launch-pad-motor-valve/assets/path-statechart.png" width="30%" height="30%">

### Casos de teste para cobertura de 100%

- Caso 1: Iniciando no estado de decisão de ativação, ao decidir acionar a válvula e em seguida decidir cancelar o acionamento, o componente não deve ser acionado;
- Caso 2: Iniciando no estado de decisão de ativação, ao decidir acionar a válvula e, caso seja o primeiro acionamento, a válvula deve permanecer acionada por 20 segundos;
- Caso 3: Iniciando no estado de decisão de ativação, ao decidir acionar a válvula e, caso seja o segundo acionamento, a válvula deve permanecer acionada por 32 segundos;
- Caso 4: Iniciando no estado de decisão de ativação, ao decidir acionar a válvula e, caso seja o terceiro acionamento, a válvula deve permanecer acionada por 40 segundos;
- Caso 5: Iniciando no estado de decisão de ativação, ao decidir acionar o motor e em seguida decidir cancelar o acionamento, o componente não deve ser acionado;
- Caso 6: Iniciando no estado de decisão de ativação, ao decidir acionar o motor este deve ser acionado por 0,2 segundos. 

## Esquemático do circuito eletrônico

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/launch-pad-motor-valve/assets/esquematico-circuito.png" width="30%" height="30%">
