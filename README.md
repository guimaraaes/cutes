# framework-teste-embarcados-arduino-nodemcu

## Atividades para realizar testes em sistemas embarcados
- Prototipar os componentes eletrônicos que vão fazer parte do Sistema Embarcado (SE).
- Definir a lógica de controle para o arduino.

- Com o Yakindu definir a Máquina de Estados Finitos (MEF) ou Statechart que traduza o comportamento esperado para o SE prototipado e codificado.
- Ainda no Yakindu definir casos de teste para garantir 100% de cobertura da MEF.

- Os casos de teste vão auxiliar a construção destes com um framework (AUnit ou ArduinoUnit) diretamente no arduino.
<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/atividades_para_testar.png" width="50%" height="50%">

## Estrutura dos algoritmos para realizar os testes
<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/diagrama_modulos.png" width="70%" height="70%">

## exemplos
### casos de teste para o pir-luz
Funcionalidades
- Luz acesa ao detectar o movimento pelo PIR
- Luz apagado quando o movimento não é detectado


### casos de teste para o exemplo do ultrasônico
Funcionalidades
- Luz pagada para distância no intervalo de \[0, 20\[ de um obstáculo até o ultrasônico;
- Luz piscando com intervalo de 0.segundos para distância no intervalo de \[20, 30\[ de um obstáculo até o ultrasônico;
- Luz pagada para distância no intervalo de \[30, infinito\[ de um obstáculo até o ultrasônico;
<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/ultrasonic.png" width="30%" height="30%">


### :mailbox: Dúvidas? Me manda um [e-mail](sguimaraaes@gmail.com) 

<img src="https://raw.githubusercontent.com/guimaraaes/guimaraaes/master/assets/card-readme.png" >

### :globe_with_meridians: para me encontrar na web
[![LinkedIn](https://img.shields.io/badge/-LINKEDIN-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/sara-guimar%C3%A3es-negreiros-aa2382155/)
[![GitHub](https://img.shields.io/badge/github-%23100000.svg?&style=for-the-badge&logo=github&logoColor=white)](https://guimaraaes.github.io/guimaraaes/)
[<img height="25" src="https://i.imgur.com/2iVxee6.png">![Lattes](https://img.shields.io/badge/lattes-%23100000?logoColor=blue&style=for-the-badge)](http://lattes.cnpq.br/7082901769077209)
