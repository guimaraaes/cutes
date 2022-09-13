# arquitetura

## estrutura dos algoritmos para realizar os testes

A arquitetura do framework CUTES foi desenvolvida utilizando padrões de projetos garantir módulos mais coesos e de fácil compreensão (Figura 5.1). A classe abstrata EmbeddedSystem vai definir o comportamento básico de SE, quando herdada, a classe especializada deve definir os atributos de description e author, além do comportamento dos métodos de configuration, setup e loop. Para cada classe especializada devem ser definidor os componentes e os criadores desses componentes.

A classe abstrata Creator utiliza o padrão de projeto Factory Method nesse padrão é definido o método createComponent para retornar objetos da classe abstrata Component. Cada classe especializada da classe Creator vai definir a forma de criar um componente especializado da classe Component.

Além disso, na classe Component são definidos atributos para o comportamento, pino e histórico do SE em cada classe são definidos métodos específicos para leitura e escrita dos componentes. O atributo de histórico é um objeto da classe History que utiliza o padrão de projeto Singleton para garantir acesso global sempre à uma mesma instância dessa classe. Assim, independente de onde a classe seja instanciada, sempre será a mesma instância.

Na classe History é definido o atributo de list para armazenar em uma lista encadeada de modo temporal as interações – instâncias da classe Interaction – ocorridas no SE e mapeadas com informações do tempo, pino e o valor da interação. De volta na classe Component, é definido um método (addHistory) para registrar as interações ocorridas no sistema embarcado. Já o atributo de comportamento é um objeto instanciado de uma especialização da classe abstrata ComponentBehavior utilizada para verificar assertivas dos casos de teste. Esta possui uma referência para a classe History e a informação no pino do componente.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-arquitetura.png" width="70%" height="70%">

Cada especialização vai definir um comportamento com base na saída ou nos comandos recebidos pelos componentes. Classes como Creator, Component e Component- Behavior possuem suas especializações armazenadas em pastas de unitis-\* pois essas unidades podem ser reaproveitadas na criações de outros SE.

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/cutes-units.png" width="70%" height="70%">

lém disso, nem todo SE vai precisar utilizar todas as especializações das pastas unitis-\*. Pela Figura 5.2 observa-se unidades de criadores (unit-creatores) para atuadores e sensores digitais, além do criador do sensor ultrasônico; para as unidades de componentes (units-components) observa-se os componentes resultantes das unidades criadoras.

Cada componente possui um comportamento que é descrito nas unidades de comportamento (unit-behaviors) do componente podendo assumir valores numéricos ou
digitais (high e low).

Para o sistema embarcado da seção 5.3.2, por exemplo, apenas foram utilizadas as especializações em cor verde na Figura. Para representar esse sistema embarcado foi definido uma classe especializada de EmbeddedSystem (ArduinoUltrasonicLight). De modo semelhante, esse sistema também poderia ser definido com o microcontrolador ESP8266 (ESP8266UltrasonicLight) com o diferencial de inserir a conexão com o Wi-Fi no método configuration.

O registro do comportamento desses sistemas é feito em uma lista temporal. As classes de teste vão utilizar esse registro para testar assertivas dos casos de teste. Caso o framework seja utilizado apenas para a criação de sistemas embarcados, é possível utilizar uma diretiva define com CREATE ENVIROMENT para que não seja registrado o comportamento do SE e a memória do sistema seja economizada.
