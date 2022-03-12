#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sample.h"
#include <commons/collections/list.h>
#include <commons/log.h>

int main(){
  t_list *mensajes;
  char temp_file[] = "logs/sample.txt"; // se creará en la raíz del proyecto
  t_log *logger = log_create(temp_file, "TEST", true, LOG_LEVEL_INFO);
  mensajes = list_create();

  list_add(mensajes, crear_mensaje_importante("holis"));
  list_add(mensajes, crear_mensaje_importante("que tal?"));

  char *_get_texto(Mensaje* mensaje) { return mensaje->texto; }

  t_list *textos = list_map(mensajes, (void *)_get_texto);

  for (int i = 0; i < list_size(textos); i++) {
    log_info(logger, "%s", list_get(textos, i));
  }

  list_destroy_and_destroy_elements(mensajes, (void *)mensaje_destroy);
  log_destroy(logger);

  return 0;
}

Mensaje* crear_mensaje_importante(char *texto) {
  Mensaje* mensaje = malloc(sizeof(Mensaje));

  mensaje->texto = strdup(texto);
  mensaje->tipo = MENSAJE_IMPORTANTE;

  return mensaje;
}

void mensaje_destroy(Mensaje* mensaje) {
  free(mensaje->texto);
  free(mensaje);
}

void imprimir_mensaje(Mensaje mensaje) {
  if (mensaje.tipo == MENSAJE_IMPORTANTE) {
    printf("ALERTA!! ");
  }

  printf("%s\n", mensaje.texto);
}