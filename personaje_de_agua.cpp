#include "personaje_de_agua.h"

Personaje_de_agua::Personaje_de_agua(string nombre, int escudo, int vidas): Personaje(nombre, escudo, vidas) {
    veces_alimentado = 0;
}

Personaje_de_agua::Personaje_de_agua(string nombre): Personaje(nombre) {
    veces_alimentado = 0;
}


Personaje_de_agua::Personaje_de_agua(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador, se_defiende) {
    veces_alimentado = 0;
}

Personaje_de_agua::Personaje_de_agua(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador) {
    veces_alimentado = 0;
}

void Personaje_de_agua::alimentar() {
    if(alcanzo_max_alimento()) {
        cout << "Ya alimentaste " << MAX_VECES_ALIMENTADO_P_AGUA << " veces a " << nombre << ". ¡El " << ALIMENTO_P_AGUA << " no cae del cielo!" << endl;
    } else {
        int energia_anterior = energia;
        if(energia >= VALOR_MIN_ENERGIA && energia <= VALOR_MAX_ENERGIA) energia += ENERGIA_RECUPERADA_P_AGUA;
        if(energia > VALOR_MAX_ENERGIA) energia = VALOR_MAX_ENERGIA;
        veces_alimentado++;
        cout << "El personaje " << nombre << " fue alimentado con " << ALIMENTO_P_AGUA << " y recupero " << energia - energia_anterior << " punto(s) de energia" << endl;
    }
}

bool Personaje_de_agua::alcanzo_max_alimento() {
    return veces_alimentado == MAX_VECES_ALIMENTADO_P_AGUA;
}

string Personaje_de_agua::de_que_elemento_soy() {
    return ELEMENTO_AGUA;
}

void Personaje_de_agua::defender() {
    if (energia >= MIN_ENERGIA_DEFENSA_AGUA) {
        energia -= MIN_ENERGIA_DEFENSA_AGUA;
        vidas += CURACION_PERSONAJE_AGUA;
        se_defiende = true;
    } else {
        cout << ENERGIA_INSUFICIENTE << ". A " << nombre << " le quedan " << energia << " puntos de energia." << endl;
        se_defiende = false;
    }
}

void Personaje_de_agua::recibe_ataque(string elemento_enemigo, int danio_recibido) {
    if (elemento_enemigo == ELEMENTO_TIERRA) danio_recibido += ATAQUE_FUERTE_TIERRA;
    else if (elemento_enemigo == ELEMENTO_FUEGO) danio_recibido = ATAQUE_DEBIL_FUEGO;
    else danio_recibido = ATAQUE_BASE_AIRE;
    
    aplicar_escudo(danio_recibido);
    vidas -= danio_recibido;
}

