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

void setup() {
  pinMode(13, OUTPUT);         // Configura o pino 13 (led interno) como saída;
  pinMode(8, INPUT_PULLUP);    // Configura pino 8 como entrada e habilita pull up interno;
}
void loop() {
  if (digitalRead(8) == LOW) { // Botão Pressionado;
    digitalWrite(13, HIGH);    // Liga led.
  }
  else {                       // Botão Não Pressionado
    digitalWrite(13, LOW);     // Desliga led.
  }
}
