/**
 * MIT License
 *
 * Copyright (c) 2014 Vida de Silício - blog.vidadesilicio.com.br
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

bool last;             // Guarda o último estado do botão;
uint32_t print_timer;  // Timer para a impressão na porta serial;
uint8_t counter = 0;   // Conta o número de mudança de estados no botão;

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP); // Configura pino 8 como entrada e habilita pull up interno;
  last = digitalRead(8);
}

void loop() {
  bool now = digitalRead(8); // Lê o estado atual do botão;
  if (now != last) {         // Checa se houve uma mudança de estado;
    ++counter;
    last = now;              // Atualiza o ultimo estado;
  }

  if (millis() - print_timer > 1000) { // Imprime a quantidade de mudanças a cada segundo;
    Serial.println(counter);
    print_timer = millis();
  }
}
