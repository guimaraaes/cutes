# Guimarães

- Criação e teste de componentes e de sistema para sistemas embarcados com arduino.

## Metodologia para Desenvolvimento de Sistemas Embarcados com Arduino e o Framework Guimarães

Nesta subseção, apresentamos a metodologia seguida para apoiar o desenvolvimento de sistemas embarcados com Arduino utilizando o framework Guimarães. Essa metodologia consiste em uma sequência de atividades agrupadas em etapas, sendo estas:

1. **Modelagem Comportamental**
2. **Plano de Teste**
3. **Prototipagem Eletrônica**
4. **Codificação com o Framework Guimarães**
5. **Análise**

Essas etapas são ilustradas na Figura abaixo:

![Figura Guimarães-atividades](inserir_link_para_imagem_aqui)

Apesar de serem utilizadas ferramentas específicas nas outras atividades da metodologia, como o *Graphor* para o diagrama de requisitos, o *Tinkercad* para documentar o circuito eletrônico e o *Yakindu Statechart Tool* para modelagem do sistema e definição dos testes, essas ferramentas podem ser substituídas por outras que também satisfaçam o propósito.

### Modelagem Comportamental

A primeira atividade do projeto consiste em elicitar e documentar os requisitos funcionais e não funcionais, assim como os componentes, em um diagrama de requisitos. Nesta atividade, foi utilizada a ferramenta *Graphor*. Seguindo, temos a criação do *statechart* para descrever o funcionamento do sistema. Nesta atividade, foi utilizada a ferramenta *Yakindu Statechart Tool*.

### Plano de Teste

Na etapa de plano de teste, temos as seguintes atividades:

- Traduzir o *statechart* em uma árvore de caminhos para auxiliar a definição dos casos de teste.
- Realizar a análise do caminho (*path*) da árvore para definir o caso de teste, identificando o caminho da árvore, o requisito funcional e os componentes utilizados no teste.
- Descrever cada caso de teste na ferramenta *Yakindu*.
- Analisar se todos os caminhos mínimos da árvore foram cobertos para decidir entre continuar criando casos de teste ou seguir para a próxima atividade.

### Prototipagem Eletrônica

Quando o critério de parada for atingido, avançamos para a etapa de prototipagem eletrônica com a elaboração do circuito eletrônico em um laboratório que disponibilize os componentes necessários, juntamente com a documentação desse circuito. Nesta atividade, foi utilizada a ferramenta *Tinkercad*.

### Codificação com o Framework Guimarães

Na etapa de codificação, temos as seguintes atividades:

- Traduzir a lógica de controle da *statechart* para a placa Arduino com o framework Guimarães.
- Traduzir também os casos de teste.

### Análise

Na etapa de análise, temos a execução dos testes. Os testes de componentes são os testes de unidade da engenharia de software e são elaborados para avaliar o comportamento de sensores e atuadores. Já os testes de sistemas são os testes de funcionalidade e avaliam as interações entre os componentes para atender a determinados requisitos funcionais.


<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/metodologia-guimaraes.png" width="100%" height="100%">

## Outros tópicos

### [Arquitetura do Guimarães](https://github.com/guimaraaes/cutes/tree/main/Cutes)

### [Exemplos de aplicação](https://github.com/guimaraaes/cutes/tree/main/examples-platformIO)

## :mailbox: Dúvidas? Me manda um [e-mail](sguimaraaes@gmail.com)
