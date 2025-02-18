# Temporizador_One_Shot
https://www.youtube.com/shorts/Zmfh-qanxrA?feature=share

# Enunciado
Este projeto utiliza o Raspberry Pi Pico W para controlar três LEDs e um botão físico. Ao pressionar o botão, os três LEDs (vermelho, azul e verde) são acesos simultaneamente. Após 3 segundos, os LEDs são desligados progressivamente a cada 3 segundos, começando pelo verde, seguido pelo azul, e finalizando com o vermelho. O sistema também implementa um mecanismo de debouncing para garantir que o botão seja detectado corretamente.

# Objetivos
Controlar três LEDs (vermelho, azul e verde) e um botão em um Raspberry Pi Pico W.
Acender os três LEDs quando o botão for pressionado.
Desligar os LEDs de forma progressiva após um tempo determinado (3 segundos para cada LED).
Implementar um sistema de debouncing para evitar múltiplas detecções do botão durante um único pressionamento.

# Descrição do Projeto
Este projeto foi desenvolvido para controlar três LEDs (vermelho, azul e verde) com base em um evento de pressionamento de botão. O código configura três pinos GPIO para os LEDs e um pino GPIO para o botão. Ao pressionar o botão, os três LEDs são ativados simultaneamente. Após 3 segundos, um temporizador faz com que os LEDs se desliguem de forma sequencial: primeiro o LED verde, depois o azul e, por último, o LED vermelho.

O código também implementa um mecanismo de debouncing para garantir que um único pressionamento do botão seja tratado corretamente, ignorando múltiplos eventos causados por flutuações de sinal do botão.

# Funcionalidade
Pressionamento do botão: Quando o botão é pressionado, todos os LEDs acendem ao mesmo tempo.
Desligamento progressivo: Após 3 segundos, os LEDs começam a ser desligados progressivamente. O LED verde é desligado primeiro, seguido pelo azul, e por último o vermelho.
Debouncing: O sistema assegura que o botão seja pressionado corretamente, ignorando múltiplos eventos causados por flutuações do sinal do botão.
Temporizadores: A sequência de desligamento dos LEDs é controlada por alarmes que são acionados a cada 3 segundos.

# Requisitos
Hardware:

OBS: Essas são as configurações do Simulador Wokwi, na placa BitDogLab tem diferenças na ordem dos LEDs.
Raspberry Pi Pico W.
Três LEDs (vermelho, azul e verde) conectados aos pinos GPIO 12, 11 e 13, respectivamente.
Um botão conectado ao pino GPIO 5.
Resistores de 330 Ohms limitadores de corrente para os LEDs e configuração de pull-up para o botão.

Software:

Sistema operacional Raspberry Pi.
Biblioteca Pico SDK para programar o Raspberry Pi Pico.
Compilador C para compilar o código.

# Requisitos de funcionamento:

O sistema deve acender todos os LEDs quando o botão for pressionado.
Os LEDs devem se apagar de forma sequencial após 3 segundos.
O sistema deve garantir que o botão não seja acionado mais de uma vez rapidamente devido ao debouncing.