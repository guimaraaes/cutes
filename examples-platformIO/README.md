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

- Detectar botão de acionamento para motor;
  - Quando acionado:
    - Ligar led vermelho por 5 segundos;
    - Após os 5 segundos, ligar led verde por 2 segundos;
  - Após os 7 segundos, verificar se o botão de cancelar acionamento foi pressionado:
    - Quando acionado:
      - Desligar todos os componentes (motor, led vermelho e led verde);
    - Quando não acionado:
     - Ligar o motor por 200 milisegundos e desligar a luz vermelha;
     - Após os 200 milisegundos, desligar o motor e a luz verde.


#### Árvore de casos de teste
  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/path-launch-pad-motor.png" width="30%" height="30%">


### launch-pad-motor-valve

#### Statechart ([acesse a documentação aqui](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/launch-pad-motor-valve))

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/statechart_launch-pad-motor-valve.png" width="50%" height="50%">

#### Funcionalidades

- Detectar botões de acionamento para motor e válvula e acionar o componente correspondente ao botão;
- Cancelar acionamento do abastecimento ou lançamento caso o botão de cancelar acionamento seja pressionado durante o tempo de verificação de 3s;
- Acionar o motor por 0,2 segundos caso o botão de lançamento seja acionado;
- Acionar a válvula solenóide por 20 segundos caso o botão de abastecimento seja acionado na primeira vez;
- Acionar a válvula solenóide por 32 segundos caso o botão de abastecimento seja acionado na segunda vez;
- Acionar a válvula solenóide por 40 segundos caso o botão de abastecimento seja acionado na terceira vez.

#### Árvore de casos de teste
  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/path-launch-pad-motor-valve.png" width="50%" height="50%">
