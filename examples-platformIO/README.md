# exemplos

## pir-light
### Funcionalidades

- Luz acesa ao detectar o movimento no sensor PIR;
- Luz apagada quando o movimento no sensor PIR não é detectado.

## ultrasonic-light
### Funcionalidades

- Luz apagada para distância no intervalo de \[0, 30\[ de um obstáculo até o ultrasônico;
- Luz ligada para distância no intervalo de \[30, infinito\[ de um obstáculo até o ultrasônico.

## launch-pad-motor
### Funcionalidades

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


## launch-pad-motor-valve
### Funcionalidades

- Detectar botões de acionamento para motor e válvula e acionar o componente correspondente ao botão;
- Cancelar acionamento do abastecimento ou lançamento caso o botão de cancelar acionamento seja pressionado durante o tempo de verificação de 3s;
- Acionar o motor por 0,2 segundos caso o botão de lançamento seja acionado;
- Acionar a válvula solenóide por 20 segundos caso o botão de abastecimento seja acionado na primeira vez;
- Acionar a válvula solenóide por 32 segundos caso o botão de abastecimento seja acionado na segunda vez;
- Acionar a válvula solenóide por 40 segundos caso o botão de abastecimento seja acionado na terceira vez.
 