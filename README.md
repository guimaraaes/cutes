# framework-teste-embarcados-arduino-nodemcu

- CUTES: Create and Units Testing to Embedded Systems.

## atividades para realizar testes em sistemas embarcados

- A primeira atividade de um projeto consiste em:

  - elicitar e documentar os requisitos funcionais e não funcionais, assim como os componentes, em um diagrama de requisitos da SysADL.
  - Seguindo com um conjunto de atividades com a ferramenta Yakindu Statechart Tool para modelar o funcionamento do sistema em statechart;
  - e definir os casos de testes que garantam cobertura de 100% da máquina modelada.

- O próximo conjunto de atividades é destinado para a criação do SE:
  - a prototipação eletrônica utilizando o Fritizing e um laboratório que disponibilize os componentes necessários seguindo com a atividade de definir a lógica de controle para o arduino com o CUTES.
  - Na atividade de teste os casos de testes do Yakindu Statechart Tool são traduzidos para C++ com o CUTES.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-atividades.png" width="100%" height="100%">
 
 ## estrutura dos algoritmos para realizar os testes

A arquitetura do framework CUTES foi desenvolvida utilizando padrões de projetos garantir módulos mais coesos e de fácil compreensão (Figura 5.1). A classe abstrata EmbeddedSystem vai definir o comportamento básico de SE, quando herdada, a classe especializada deve definir os atributos de description e author, além do comportamento dos métodos de configuration, setup e loop. Para cada classe especializada devem ser definidor os componentes e os criadores desses componentes.

A classe abstrata Creator utiliza o padrão de projeto Factory Method nesse padrão é definido o método createComponent para retornar objetos da classe abstrata Component. Cada classe especializada da classe Creator vai definir a forma de criar um componente especializado da classe Component.

Além disso, na classe Component são definidos atributos para o comportamento, pino e histórico do SE em cada classe são definidos métodos específicos para leitura e escrita dos componentes. O atributo de histórico é um objeto da classe History que utiliza o padrão de projeto Singleton para garantir acesso global sempre à uma mesma instância dessa classe. Assim, independente de onde a classe seja instanciada, sempre será a mesma instância.

Na classe History é definido o atributo de list para armazenar em uma lista encadeada de modo temporal as interações – instâncias da classe Interaction – ocorridas no SE e mapeadas com informações do tempo, pino e o valor da interação. De volta na classe Component, é definido um método (addHistory) para registrar as interações ocorridas no sistema embarcado. Já o atributo de comportamento é um objeto instanciado de uma especialização da classe abstrata ComponentBehavior utilizada para verificar assertivas dos casos de teste. Esta possui uma referência para a classe History e a informação no pino do componente.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-arquitetura.png" width="100%" height="100%">

Cada especialização vai definir um comportamento com base na saída ou nos comandos recebidos pelos componentes. Classes como Creator, Component e Component- Behavior possuem suas especializações armazenadas em pastas de unitis-\* pois essas unidades podem ser reaproveitadas na criações de outros SE.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-units.png" width="100%" height="100%">

lém disso, nem todo SE vai precisar utilizar todas as especializações das pastas unitis-\*. Pela Figura 5.2 observa-se unidades de criadores (unit-creatores) para atuadores e sensores digitais, além do criador do sensor ultrasônico; para as unidades de componentes (units-components) observa-se os componentes resultantes das unidades criadoras.

Cada componente possui um comportamento que é descrito nas unidades de comportamento (unit-behaviors) do componente podendo assumir valores numéricos ou
digitais (high e low).

Para o sistema embarcado da seção 5.3.2, por exemplo, apenas foram utilizadas as especializações em cor verde na Figura. Para representar esse sistema embarcado foi definido uma classe especializada de EmbeddedSystem (ArduinoUltrasonicLight). De modo semelhante, esse sistema também poderia ser definido com o microcontrolador ESP8266 (ESP8266UltrasonicLight) com o diferencial de inserir a conexão com o Wi-Fi no método configuration.

O registro do comportamento desses sistemas é feito em uma lista temporal. As classes de teste vão utilizar esse registro para testar assertivas dos casos de teste. Caso o framework seja utilizado apenas para a criação de sistemas embarcados, é possível utilizar uma diretiva define com CREATE ENVIROMENT para que não seja registrado o comportamento do SE e a memória do sistema seja economizada.

## análise de consumo de memória

Para a Figura a seguir foram utilizadas as informações retornadas pela PlatformIO sobre o uso das memórias RAM e Flash do microcontrolador. Inicialmente é apresentado o consumo das memórias para a criação da lógica de controle sem o framework, seguindo com o consumo utilizando o CUTES tanto no ambiente de criação (CREATE_ENVIROMENT) como no ambiente de teste (TEST_ENVIROMENT). Para o ambiente de teste é possível analisar o consumo tanto com o AUnit e o Arduino Unit. Para todos os cenários foi utilizado o mesmo exemplo.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-memória.png" width="100%" height="100%">

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
