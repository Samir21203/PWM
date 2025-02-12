# Controle de Servo Motor com Raspberry Pi Pico W (PWM)

Este projeto utiliza o Raspberry Pi Pico W para controlar um servo motor através de sinais PWM (Pulse Width Modulation). O servo motor pode ser movido para diferentes posições (0°, 90°, 180°) e também realiza movimentos suaves entre essas posições.

## Requisitos

- **Raspberry Pi Pico W**
- **Servo Motor**
- **Fios de conexão (Jumpers)**
- **Fonte de alimentação para o servo (se necessário)**
- **OBS: Pode ser realizado pelo simulador Wokwi**

## Conexões

- O servo motor está conectado ao **GPIO 22** do Raspberry Pi Pico W.

## Configurações do PWM

- A frequência do PWM está configurada para **50Hz**.
- O ciclo de trabalho do PWM é ajustado para controlar a posição do servo.
  - **0° (mínimo):** 500 microsegundos
  - **90° (médio):** 1470 microsegundos
  - **180° (máximo):** 2400 microsegundos

## Funcionamento

1. O código configura o PWM na GPIO 22 para controlar o servo.
2. A posição inicial do servo é configurada para **180°**.
3. O servo então se move para as posições **90°** e **0°**, com um atraso de 5 segundos entre as mudanças.
4. Após isso, o servo realiza movimentos suaves entre **0°** e **180°** com um incremento de **5 microsegundos** a cada ciclo, criando uma animação suave.

## Como Compilar e Carregar o Código

1. Clone este repositório em sua máquina.
2. Configure o ambiente de desenvolvimento do Raspberry Pi Pico W (instale o plugin Pico SDK no Visual Studio Code).
3. Importe o projeto pelo plugin do Pico SDK.
4. Compile o código e carregue o arquivo compilado no Raspberry Pi Pico W utilizando o plugin.
5. Conecte o servo motor ao GPIO 22 e forneça alimentação adequada.
6. Execute o código e observe os movimentos do servo motor.

## Licença

Este projeto está licenciado sob a MIT License - consulte o arquivo [LICENSE](LICENSE) para mais detalhes.
