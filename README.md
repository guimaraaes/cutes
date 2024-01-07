# Documentação do Framework Guimarães

- Apoiando a construção de testes automatizados guiados por documentação para sistemas embarcados com Arduino.
- Acesse a lib do Framework Guimarães [aqui](https://github.com/guimaraaes/FrameworkGuimaraes/tree/main)

## Metodologia para Desenvolvimento de Sistemas Embarcados com Arduino e o Framework Guimarães

Nesta subseção, apresentamos a metodologia seguida para apoiar o desenvolvimento de sistemas embarcados com Arduino utilizando o framework Guimarães. Essa metodologia consiste em uma sequência de atividades agrupadas em etapas, sendo estas:

1. **Modelagem Comportamental**
2. **Plano de Teste**
3. **Prototipagem Eletrônica**
4. **Codificação com o Framework Guimarães**
5. **Análise**

Essas etapas são ilustradas na Figura abaixo:
<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/metodologia-guimaraes.png" width="100%" height="100%">

Apesar de serem utilizadas ferramentas específicas nas outras atividades da metodologia, como o *Graphor* para o diagrama de requisitos, o *Tinkercad* para documentar o circuito eletrônico e o *Yakindu Statechart Tool* para modelagem do sistema e definição dos testes, essas ferramentas podem ser substituídas por outras que também satisfaçam o propósito.

### Modelagem Comportamental

A primeira atividade do projeto consiste em elicitar e documentar os requisitos funcionais e não funcionais, assim como os componentes, em um diagrama de requisitos. Nesta atividade, foi utilizada a ferramenta *Graphor*. 

### Plano de Teste

Essa etapa envolve a definição dos casos de teste e a análise dos critérios para determinar quando parar a criação desses casos. Os exemplos de caso presentes na documentação deste repositório seguem um plano de teste com statechart ou utilizam BDD (Behavior Driven Development).

### Prototipagem Eletrônica

Quando o critério de parada for atingido, avançamos para a etapa de prototipagem eletrônica com a elaboração do circuito eletrônico em um laboratório que disponibilize os componentes necessários, juntamente com a documentação desse circuito. Nesta atividade, foi utilizada a ferramenta *Tinkercad*.

### Codificação com o Framework Guimarães

Na etapa de codificação, temos as seguintes atividades:

- Traduzir a lógica de controle da *statechart* para a placa Arduino com o framework Guimarães.
- Traduzir também os casos de teste.

### Análise

Na etapa de análise, temos a execução dos testes. Os testes de componentes são os testes de unidade da engenharia de software e são elaborados para avaliar o comportamento de sensores e atuadores. Já os testes de sistemas são os testes de funcionalidade e avaliam as interações entre os componentes para atender a determinados requisitos funcionais.



## Outros tópicos

### [Arquitetura do Guimarães](https://github.com/guimaraaes/cutes/tree/main/FrameworkGuimaraes)

### [Exemplos de aplicação](https://github.com/guimaraaes/cutes/tree/main/examples-platformIO)

## :mailbox: Dúvidas? Me manda um [e-mail](sguimaraaes@gmail.com)
