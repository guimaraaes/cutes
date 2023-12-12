# Arquitetura do Framework Guimarães

A arquitetura do *framework* Guimarães, apresentada na Figura abaixo, foi desenvolvida com o objetivo de permitir a codificação do comportamento do sistema embarcado, além da execução de testes em componentes e no sistema através do código. Esse *framework* foi desenvolvido para ser utilizado na placa Arduino.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-arquitetura.png" width="70%" height="70%">

Aqui está a descrição detalhada da arquitetura:

## Classe Abstrata `EmbeddedSystem`

A classe abstrata `EmbeddedSystem` define o comportamento básico de um Sistema Embarcado (*SE*). Quando herdada, a classe especializada deve definir os atributos `description` e `author`, além do comportamento dos métodos `configuration`, `setupES`, `loopES` e o método `runComponentTests` para executar os testes de todos os componentes.

## Classe Abstrata `Creator`

A classe abstrata `Creator` utiliza o padrão de projeto *Factory Method*. Nesse padrão, é definido o método `createComponent` para retornar objetos da classe abstrata `Component`. Cada subclasse especializada da classe `Creator` vai definir a forma de criar um componente especializado da classe `Component`.

## Classe `Component`

Na classe `Component`, são definidos atributos para o comportamento (`behavior`), pino (`pin`) e histórico (`history`) do Sistema Embarcado (*SE*). O atributo `history` é um objeto da classe `History` que utiliza o padrão de projeto *Singleton* para garantir acesso global sempre à uma mesma instância dessa classe pelo método `getInstance`.

## Classe `History`

Na classe `History`, é definido o atributo de `list` para armazenar em uma lista encadeada as interações ocorridas no Sistema Embarcado (*SE*). Esta classe utiliza o padrão de projeto *Singleton* para garantir acesso global sempre à uma mesma instância dessa classe pelo método `getInstance`. Isso permite salvar o comportamento das classes especializadas de `EmbeddedSystem` em histórico utilizado para a execução dos testes de sistema. O histórico dessa classe é gerado em uma lista temporal que mapeia cada interação realizada nos componentes.

As interações possuem informações de tempo (`time`), pino (`pin`) e o valor da interação (`value`). Assim, os valores da interação (`value`) mapeiam o comportamento do componente (`pin`) durante a execução do sistema (`time`).

## Classe `Behavior`

O atributo de comportamento (`behavior`) na classe `Component` é um objeto instanciado de uma especialização da classe abstrata `Behavior` utilizada para verificar assertivas dos casos de teste de sistema. Cada especialização desta classe define um comportamento com base na saída ou nos comandos recebidos pelos componentes.

## Classe `SystemTests`

A classe `SystemTests` é utilizada para testar as funcionalidades do sistema embarcado. Ela possui o atributo de histórico (`history`) para acessar as interações desse sistema. Esta classe ainda possui funcionamento dos métodos `enter` e `exit`, padrões para os casos de teste de sistema, e o método `runSystemTests` para executar todos os casos de teste de sistema. A comunicação entre essa classe e a classe de `EmbeddedSystem` é realizada através no arquivo `main` apresentado mais adiante.

## Unidades de Criação e Componentes

Classes como `Creator`, `Component` e `Behavior` possuem suas especializações armazenadas em pastas de `unit-creators, unit-components e unit-behaviors`, respectivamente, pois essas unidades podem ser reaproveitadas na criação de outros Sistemas Embarcados (*SE*) com a placa Arduino.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-units.png" width="70%" height="70%">

Para as classes especializadas de `unit-behaviors`, são definidas as funções para verificar o funcionamento dos componentes nos testes de sistema. As funções que iniciam com `raiseSensor*` verificam se o sensor está assumindo um valor específico (`High` ou `Low`) para a classe `HighLow` ou se está em um intervalo numérico (`Vi` e `Vf`) para a classe `Numeric`. Já as funções que iniciam com `isActuator*` seguem o mesmo raciocínio e verificam o funcionamento dos componentes atuadores.

