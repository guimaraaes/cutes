# pir-light

## Elicitar requisitos

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/pir-light/assets/requisitos.png" width="100%" height="100%">

## Statechart ([acesse a documentação aqui com os casos de teste](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/pir-light))

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/pir-light/assets/statechart.png" width="50%" height="50%">

## Árvore de caminhos do Statechart 

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/pir-light/assets/path-statechart.png" width="30%" height="30%">

### Casos de teste para atingir todos-os-caminhos-mínimos

- Caso 1: Iniciando no estado de decisão, após ser detectado o movimento, verificar se a luz está em estado de ligado;
- Caso 2: Iniciando no estado de decisão, após não ser detectado nenhum movimento, verificar se a luz está em estado de desligado. 

## Esquemático do circuito eletrônico

<img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/examples-platformIO/pir-light/assets/esquematico-circuito.png" width="30%" height="30%">

## Arquitetura do projeto
Ao criar o projeto com o PlatformIO, a estrutura do projeto deve ser atualizada para a seguinte:

```
.
├── EmbeddedSystem          # System code with: configuration, setup, loop and component tests 
├── lib                     # ArduinoUnit lib and others needed
├── src                     # Source files 
├── test                    # System tests 
└── README.md               # Documentation
```

## Códificação do SE

Em `EmbeddedSystem/EmbeddedSystem.cpp` temos a classe `PirLight` com o funcionamento do sistema através da definição de:

- Instâncias dos componentes (sem configuração dos pinos);
- Método construtor `PirLight` para receber a descrição e o nome do autor do sistema (ao final da classe é criada a instância `embeddedSystem` com essas informações);
- Método de `configuration` (não aplicado nesse exemplo);
- Método `setupES` para criar os componentes com a configuração dos pinos com instâncias das classes de criação;
- Método `loopES` para implementar a lógica de controle;
- Método `runComponentTests` para testar os componentes.

```
class PirLight : public EmbeddedSystem
{

  public:
    ActuatorDigital *light;
    SensorDigital *pir;

    PirLight(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setupES()
    {
        ...
    };
    
    void loopES()
    {
        ...
    };

    void runComponentTests()
    {
        ...
    }
};

PirLight embeddedSystem = PirLight("sistema embarcado acender luz enquanto movimento for detectado", "Sara Guimarães");
```

### setupES

- Método `setupES` para criar os componentes com a configuração dos pinos com instâncias das classes de criação;

```
    void setupES()
    {
        CreatorActuatorDigital *creatorActuatorDigital = new CreatorActuatorDigital();
        light = creatorActuatorDigital->createComponent(13);

        CreatorSensorDigital *creatorSensorDigital = new CreatorSensorDigital();
        pir = creatorSensorDigital->createComponent(3);
    };
```

### loopES

- Método `loopES` para implementar a lógica de controle;

```
    void loopES()
    {
        if (pir->read() == HIGH)
        {
            light->write(HIGH);
            delay(1000);
        }
        if (pir->read() == LOW)
        {
            light->write(LOW);
            delay(1000);
        }
    };
```

### runComponentTests

- Método `runComponentTests` para testar os componentes.

```
    void runComponentTests()
    {
        pir->componentTest();
        light->componentTest();
    }
```
Todos os componentes são testados através de interação com o desenvolvedor. A seguir são descritas as mensagens padrão enviadas pelo terminal para que o desenvolvedor valide se o componente está funcionando corretamente ou não.

#### Componente tipo sensor

```
Begining component test to component in pin $PIN
--- Put within 5 seconds component with the value $VALUE
--- Component test result: you must assert. Wait to answer.
---- Value expected $VALUE_EXPECTED
---- Value readed $VALUE_READED
```

#### Componente tipo atuador

```
Begining component test to component in pin $PIN
--- Verify if within 2 seconds component is during 5 second with the value $VALUE
--- Component test result: you must assert. Wait to answer.
```

## Códificação do SystemTests
Em `test/SystemTests.cpp` temos a classe `PirLightSystemTests` com o funcionamento do sistema através da definição de:

- Componentes;
- Método construtor `PirLightSystemTests` (ao final da classe é criada a instância `systemTests`);
- Método de `enter` executar o funcionamento do sistema e salvar as interações em um histórico;
- Método `exit` limpar o histórico;
- Método `run` executar todos os casos de teste.

Os métodos `enter` e `exit` são executados no início e no final de cada caso de teste, respectivamente.

```
class PirLightSystemTests : public SystemTests
{
    public:
        PirLightSystemTests(){};
        void enter(String name)
        {
            Serial.println(name);
            delay(3000);
            embeddedSystem.loopES();
        };

        void exit()
        {
            history->list->clear();
        };

        void run()
        {
            Test::run();
        }
};

PirLightSystemTests systemTests = PirLightSystemTests();
```
### Casos de teste

Cada caso de teste é resultado da tradução do caso gerado no Yakindu para a implementação em C++ com o Framework Guimarães.

#### Caso 1: teste para luz em estado ligado

- No Yakindu

```
@Test
operation testLightOn() {
	enter
	raise pir.ON
	assert light.ON
exit
}
```

- Com o Framework Guimarães

```
test(testLightOn)
{
    systemTests.enter("testLightOn");
    assertTrue(embeddedSystem.pir->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.light->behavior->isActuatorHigh());
    systemTests.exit();
}

```

#### Caso 2: teste para luz em estado desligado

- No Yakindu
```
@Test
operation testLightOff() {
	enter
	raise pir.OFF
	assert light.OFF
	exit
}
```

- Com o Framework Guimarães

```
test(testLightOff)
{
    systemTests.enter("testLightOff");
    assertTrue(embeddedSystem.pir->behavior->raiseSensorLow());
    assertTrue(embeddedSystem.light->behavior->isActuatorLow());
    systemTests.exit();
}
```

## Arquivo main
O projeto pode atuar em três ambientes distintos:
- Criação (`CREATE_ENVIROMENT`): Apenas o arquivo `EmbeddedSystem/EmbeddedSystem.cpp` com a lógica de funcionamento do arduino é executado;
- Testes de componente (`COMPONENT_TESTS_ENVIROMENT`): Apenas os testes de componentes do método `runComponentTests` do arquivo `` são executados;
- Testes do sistema (`SYSTEM_TESTS_ENVIROMENT`): Apenas os testes de sistema são executados do arquivo `test/SystemTests.cpp`.

No aquivo `src/main.cpp` é definido o ambiente de execução. Apenas um `define` deve estar ativo por vez:

```
#define CREATE_ENVIROMENT
// #define COMPONENT_TESTS_ENVIROMENT
// #define SYSTEM_TESTS_ENVIROMENT
```

A seguir são incluídas as bibliotecas necessárias para execução do projeto:

```
#include <Arduino.h>

#include "../lib/FrameworkGuimaraes/FrameworkGuimaraes.h"

#include "../EmbeddedSystem/EmbeddedSystem.cpp"

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "../test/SystemTests.cpp"
#endif
```

Seguindo com o método `setup` (todos os ambientes precisam do setup do embeddedSystem para execução):

```
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  embeddedSystem.setupES();
}
```

Por fim, a execução em `loop` do ambiente definido:

```
void loop()
{
// put your main code here, to run repeatedly:
#ifdef CREATE_ENVIROMENT
  embeddedSystem.loopES();
#endif

#ifdef COMPONENT_TESTS_ENVIROMENT
  embeddedSystem.runComponentTests();

#endif

#ifdef SYSTEM_TESTS_ENVIROMENT
  systemTests.run();
#endif
}
```
