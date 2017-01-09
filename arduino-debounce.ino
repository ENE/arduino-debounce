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

bool stable;    // Guarda o último estado estável do botão;
bool unstable;  // Guarda o último estado instável do botão;
uint32_t bounce_timer;
uint8_t counter = 0;

bool changed() {
  bool now = digitalRead(8);   // Lê o estado atual do botão;
  if (unstable != now) {       // Checa se houve mudança;
    bounce_timer = millis();   // Atualiza timer;
    unstable = now;            // Atualiza estado instável;
  }
  else if (millis() - bounce_timer > 10) {  // Checa o tempo de trepidação acabou;
    if (stable != now) {           // Checa se a mudança ainda persiste;
      stable = now;                  // Atualiza estado estável;
      return 1;
    }
  }
  return 0;
}

void setup() {
  Serial.begin(9600);        // Configura comunicação serial a uma taxa de 9600 bauds.
  pinMode(8, INPUT_PULLUP);  // Configura pino 8 como entrada e habilita pull up interno;
  stable = digitalRead(8);
}

void loop() {
  if (changed()) {
    ++counter;
    Serial.println(counter);
  }

  // Outras tarefas;
}
