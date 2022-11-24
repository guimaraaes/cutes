# pir-light


## Elicitar requisitos

- Luz acesa ao detectar o movimento no sensor PIR;
- Luz apagada quando o movimento no sensor PIR não é detectado.

## Statechart ([acesse a documentação aqui com os casos de teste](https://github.com/guimaraaes/cutes/tree/main/examples-eclipseYakindu/pir-light))

## Árvore de caminhos do Statechart 

  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/path-pir-light.png" width="30%" height="30%">

### Casos de teste para cobertura de 100%

- Caso 1: Iniciando no estado de decisão, após ser detectado o movimento, verificar se a luz está em estado de ligado;
- Caso 2: Iniciando no estado de decisão, após não ser detectado nenhum movimento, verificar se a luz está em estado de desligado. 

## Esquemático do circuito eletrônico

  <img  src="https://github.com/guimaraaes/metodologia-teste-embarcados-arduino-nodemcu/blob/main/assets/statechart_pir-light.png" width="50%" height="50%">

## Arquitetura do projeto
Ao criar o projeto com o PlatformIO, a estrutura do projeto deve ser atualizada para a seguinte:

```
.
├── embedded-system         # System code with: configuration, setup, loop and unit tests 
├── lib                     # ArduinoUnit lib and others needed
├── src                     # Source files 
├── test                    # System tests 
└── README.md               # Documentation
```

## Códificação do SE com CUTES

Em `embedded-system/embedded-system.cpp` temos a classe `PirLight` com o funcionamento do sistema através da definição de:

- Instâncias dos componentes (sem configuração dos pinos);
- Método construtor `PirLight` para receber a descrição e o nome do autor do sistema (ao final da classe é criada a instância `pirLight` com essas informações);
- Método de `configuration` (não aplicado nesse exemplo);
- Método `setup` para criar os componentes com a configuração dos pinos com instâncias das classes de criação;
- Método `loop` para implementar a lógica de controle;
- Método `unitTests` para testar os componentes.

```
class PirLight : public EmbeddedSystem
{

  public:
    ActuatorDigital *light;
    SensorDigital *pir;

    PirLight(String description, String author) : EmbeddedSystem(description, author){};
    void configuration(){};

    void setup()
    {
        ...
    };
    
    void loop()
    {
        ...
    };

    void runUnitTests()
    {
        ...
    }
};

PirLight pirLight = PirLight("sistema embarcado acender luz enquanto movimento for detectado", "Sara Guimarães");
```

### setup

- Método `setup` para criar os componentes com a configuração dos pinos com instâncias das classes de criação;

```
    void setup()
    {
        CreatorActuatorDigital *creatorActuatorDigital = new CreatorActuatorDigital();
        light = creatorActuatorDigital->createComponent(13);

        CreatorSensorDigital *creatorSensorDigital = new CreatorSensorDigital();
        pir = creatorSensorDigital->createComponent(3);
    };
    
```

### loop

- Método `loop` para implementar a lógica de controle;

```
    void loop()
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

### unitTests

- Método `unitTests` para testar os componentes.

```
    void runUnitTests()
    {
        pir->unitTest();
        light->unitTest();
    }
```

## Códificação do SystemTests com CUTES 
Em `test/test.cpp` temos a classe `PirLightSystemTests` com o funcionamento do sistema através da definição de:

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
            pirLight.loop();
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
```
### Casos de teste

Cada caso de teste é resultado da tradução do caso gerado no Yakindu para a implementação em C++ com o CUTES.

#### Caso 1: teste para luz em estado ligado

- No Yakindu

```
    @Test
	operation testLightOn() {
		enter
		raise pir.ON
 		assert light.ON
 		proceed 1s
	}
```

- Com CUTES

```
test(testLightOn)
{
    systemTests.enter("testLightOn");

    assertTrue(!pirLight.pir->behavior->isSensorHigh());

    assertTrue(pirLight.light->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(4 * 1000));

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
 		proceed 1s
	}
```

- Com CUTES

```
test(testLightOff)
{
    systemTests.enter("testLightOff");

    assertTrue(pirLight.pir->behavior->isSensorLow());

    assertTrue(pirLight.light->behavior->isActuatorLow());

    assertTrue(history->proceedTime(4 * 1000));

    systemTests.exit();
}
```

## Arquivo main
```

```


