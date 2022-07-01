# framework-teste-embarcados-arduino-nodemcu
- CUTES: Create and Units Testing to Embedded Systems.

## atividades para realizar testes em sistemas embarcados
- Realizar a elicitação de requisitos (funcionais para essa etapa) e criar o diagrama de requisitos com o sysADL.
- Em paralelo podem ser feitas as atividades de:
  - Sistema Embarcado com Arduino
    - Prototipagem de eletrônica do circuito realizando o designer no fritizing e a contrução em laboratório com ferramentas adequadas.
    - utilizar o framework cutes e a plataformio para codificar em c++ a programação responsável por controlar o sistema embarcado.

  - Documentação
    - desenhar o statechart que represente o funcionamento adequado do sistema embarcado.
    - criar os casos de teste que garam cobertura de 100% da máquina de estados.
- Tendo finalizado as etapas anteriores, utilizando o framework cutes e a plataformio é possível codificar os casos de teste através de um framework para teste(AUnit ou ArduinoUnit, por exemplo).


<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/activies_to_test.png" width="100%" height="100%">
 
 ## estrutura dos algoritmos para realizar os testes

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/diagrama_classes.png" width="100%" height="100%">

## exemplos
### casos de teste para o pir-light
<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/statechart_pir-light.png" width="50%" height="50%">

Funcionalidades
- Luz acesa ao detectar o movimento pelo PIR
- Luz apagado quando o movimento não é detectado
<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/casetest_pir-light.png" width="30%" height="30%">


### casos de teste para o exemplo do ultrasônico
<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/statechart_ultrasonic.png" width="50%" height="50%">

Funcionalidades
- Luz pagada para distância no intervalo de \[0, 20\[ de um obstáculo até o ultrasônico;
- Luz piscando com intervalo de 0.segundos para distância no intervalo de \[20, 30\[ de um obstáculo até o ultrasônico;
- Luz pagada para distância no intervalo de \[30, infinito\[ de um obstáculo até o ultrasônico;
<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/casetest_ultrasonic.png" width="30%" height="30%">

## considerações

### :mailbox: Dúvidas? Me manda um [e-mail](sguimaraaes@gmail.com) 

<img src="https://raw.githubusercontent.com/guimaraaes/guimaraaes/master/assets/card-readme.png" >

### :globe_with_meridians: para me encontrar na web
[![LinkedIn](https://img.shields.io/badge/-LINKEDIN-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/sara-guimar%C3%A3es-negreiros-aa2382155/)
[![GitHub](https://img.shields.io/badge/github-%23100000.svg?&style=for-the-badge&logo=github&logoColor=white)](https://guimaraaes.github.io/guimaraaes/)
[<img height="25" src="https://i.imgur.com/2iVxee6.png">![Lattes](https://img.shields.io/badge/lattes-%23100000?logoColor=blue&style=for-the-badge)](http://lattes.cnpq.br/7082901769077209)
