
# ultrasonic-light

## Elicitar requisitos

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/ultrasonic-light/assets/requisitos.png" width="80%" height="80%">

## Statechart ([acesse a documentação aqui com os casos de teste](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/ultrasonic-light))

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/ultrasonic-light/assets/statechart.png" width="50%" height="50%">

## Árvore de caminhos do Statechart 

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/ultrasonic-light/assets/path-statechart.png" width="30%" height="30%">

### Casos de teste para cobertura de 100%

- Caso 1: Iniciando no estado de decisão, após ser detectado o objeto a uma distância menor que 30 cm, verificar se a luz está em estado de desligado;
- Caso 2: Iniciando no estado de decisão, após não ser detectado nenhum objeto a uma distância maior ou igual a 30 cm, verificar se a luz está em estado de ligado. 

## Esquemático do circuito eletrônico

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/pir-light/assets/esquematico-circuito.png" width="30%" height="30%">
