# exemplos

### pir-light

#### Statechart ([acesse a documentação aqui](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/pir-light))

  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/statechart_pir-light.png" width="50%" height="50%">

#### Funcionalidades

- Luz acesa ao detectar o movimento no sensor PIR;
- Luz apagado quando o movimento no sensor PIR não é detectado.

#### Árvore de casos de teste

  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/path-pir-light.png" width="30%" height="30%">

### ultrasonic-light

#### Statechart ([acesse a documentação aqui](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/ultrasonic-light))

  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/statechart_ultrasonic.png" width="50%" height="50%">

#### Funcionalidades

- Luz pagada para distância no intervalo de \[0, 20\[ de um obstáculo até o ultrasônico;
- Luz piscando com intervalo de 0.segundos para distância no intervalo de \[20, 30\[ de um obstáculo até o ultrasônico;
- Luz pagada para distância no intervalo de \[30, infinito\[ de um obstáculo até o ultrasônico.

#### Árvore de casos de teste

  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/path-ultrasonic-light.png" width="50%" height="50%">


### launch-pad-motor

#### Statechart ([acesse a documentação aqui](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/launch-pad-motor))

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/statechart_launch-pad-motor.png" width="50%" height="50%">

#### Funcionalidades

- Detectar botões de acionamento para motor e válvula e acionar o componente correspondente ao botão;
- Cancelar acionamento do abastecimento ou lançamento caso o botão de cancelar acionamento seja pressionado durante o tempo de verificação de 3s;
- Acionar o motor por 0,2 segundos caso o botão de lançamento seja acionado;
- Acionar a válvula solenóide por 20 segundos caso o botão de abastecimento seja acionado na primeira vez;
- Acionar a válvula solenóide por 32 segundos caso o botão de abastecimento seja acionado na segunda vez;
- Acionar a válvula solenóide por 40 segundos caso o botão de abastecimento seja acionado na terceira vez.

#### Árvore de casos de teste
  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/path-launch-pad-motor.png" width="30%" height="30%">
