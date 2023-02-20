
# launch-pad-motor

## Elicitar requisitos

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/launch-pad-motor/assets/requisitos.png" width="100%" height="100%">

## Statechart ([acesse a documentação aqui com os casos de teste](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/launch-pad-motor))

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/launch-pad-motor/assets/statechart.png" width="50%" height="50%">

## Árvore de caminhos do Statechart 

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/launch-pad-motor/assets/path-statechart.png" width="50%" height="50%">

### Casos de teste para cobertura de 100%

- Caso 1: Iniciando no estado de decisão de ativação, ao decidir acionar o motor deve ser verificado o estado 1 de preparação para acionamento com o led vermelho ligado por 5 segundos;
- Caso 2: Iniciando no estado de decisão de ativação, ao decidir acionar o motor deve ser verificado o estado 2 de preparação para acionamento com o led verde ligado por 2 segundos;
- Caso 3: Iniciando no estado de decisão de ativação, ao decidir acionar o motor e em seguida decidir cancelar o acionamento, o componente não deve ser acionado;
- Caso 4: Iniciando no estado de decisão de ativação, ao decidir acionar o motor este deve ser acionado por 0,2 segundos. 
- Caso 4: Iniciando no estado de decisão de ativação, ao decidir acionar o motor este deve ser acionado por 0,2 segundos e posteriomente todos os componentes são desligados. 

## Esquemático do circuito eletrônico

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/launch-pad-motor/assets/esquematico-circuito.png" width="40%" height="40%">
