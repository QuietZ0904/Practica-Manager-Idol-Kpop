#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[30];
    int bonus;
    int vigencia; 
} Cancion;

typedef struct {
    const char nombre[30];
    int popularidad;
    int energia;
    int energia_Max;
    int fans;
    Cancion *cancion;
} Idol;

typedef struct {
    char nombre[30];
    Idol miembros[4];
    int n;
    Idol *lider;
} Grupo;

void mostrar(const Idol *i);
int limitar(int valor, int minimo, int maximo);
void ensayar(Idol *i);
void descansar(Idol *i);
int esta_activa(const Idol *i);
void cambiar_por_valor(Idol jennie);
void cambiar_por_apuntador(Idol *jennie);
int colaboracion(Idol *a, Idol *b);
void asignar_cancion(Idol *i, Cancion *c);
int popularidad_total(const Idol *i);
int cambiar_lider(Grupo *g, Idol *nueva);
void mostrar_grupo(const Grupo *g);
int contar_activas(const Grupo *g);
Idol *idol_mas_cansada(Grupo *g);
void dar_concierto(Grupo *g);
void mostrar_cancion_lider(const Grupo *g);
void preparar_presentacion(Grupo *g);

int main(void) {
    Idol jennie = {"jennie", 50, 100, 100, 12000, NULL};
    Idol rose = {"rose", 50, 100, 100, 12000, NULL};
    Idol lisa = {"lisa", 40, 90, 100, 10000, NULL};

    Idol *p = &jennie;
    printf("%d\n", jennie.fans);
    printf("%d\n", (*p).fans);    
    printf("%d\n", p->fans);
    printf("%p %p\n", (void *)p, (void *)&jennie);

    mostrar(&jennie);

    limitar(-5, 0, 100);
    limitar(150, 0, 100);
    limitar(40, 0, 100);

    for (int i = 0; i < 20; i++) {
        ensayar(&jennie);
        descansar(&jennie);
    }

    printf("El idol esta activo(@) : %d \n", esta_activa(&jennie));

    printf("\nPASO POR VALOR\n");
    printf("Antes: energia = %d\n", jennie.energia);
    cambiar_por_valor(jennie);
    printf("Despues: energia = %d\n", jennie.energia);

    printf("PASO POR APUNTADOR\n");
    printf("Antes: energia = %d\n", jennie.energia);
    cambiar_por_apuntador(&jennie);
    printf("Despues: energia = %d\n", jennie.energia);

    jennie.energia = 100;

    colaboracion(&jennie, &jennie);
    colaboracion(NULL, &rose);
    colaboracion(&jennie, &rose);
    
    Cancion discos[2] = {{"Starlight", 10, 3}, {"Nova", 5, 6}};

    asignar_cancion(&jennie, &discos[0]);
    asignar_cancion(&rose, &discos[0]);
    printf("Jennie y Rose ahora comparten la cancion: %s\n", jennie.cancion->nombre);

    asignar_cancion(&jennie, NULL);
    printf("Despues de quitar cancion, cancion de Jennie es: %s\n", 
           (jennie.cancion == NULL) ? "NULL (Sin cancion)" : jennie.cancion->nombre);
    asignar_cancion(&jennie, &discos[0]);

    Idol *turno = &jennie;
    Idol *otra = &rose;

    while (esta_activa(turno) && esta_activa(otra)) {
        printf("Le toca ensayar a %s (Energia: %d)\n", turno->nombre, turno->energia);
        ensayar(turno);
        
        Idol *temp = turno;
        turno = otra;
        otra = temp;
    }

    if (esta_activa(turno)) {
        printf("--> %s conserva energia (%d pts) y gana el ensayo.\n", turno->nombre, turno->energia);
    } else {
        printf("--> %s conserva energia (%d pts) y gana el ensayo.\n", otra->nombre, otra->energia);
    }

    jennie.energia = 100;
    rose.energia = 80;

    printf("Popularidad total de Jennie (con bono): %d\n", popularidad_total(&jennie));

    Grupo lumina = {"Lumina",{jennie, rose, lisa},3,NULL};

    if (cambiar_lider(&lumina, &lumina.miembros[0])) {
        printf("Nueva lider asignada: %s (Fans: %d)\n", lumina.lider->nombre, lumina.lider->fans);
    }

    printf("\nIntegrantes del Grupo:\n");
    mostrar_grupo(&lumina);

    printf("Integrantes activas: %d\n", contar_activas(&lumina));

    Idol *cansada = idol_mas_cansada(&lumina);
    if (cansada != NULL) {
        printf("La mas cansada es %s con energia %d\n", cansada->nombre, cansada->energia);
    }

    mostrar_cancion_lider(&lumina);

    printf("\nEjecutando preparar_presentacion():\n");
    preparar_presentacion(&lumina);

    printf("&lumina.miembros[0] = %p\n", (void *)&lumina.miembros[0]);
    printf("lumina.miembros + 0  = %p\n", (void *)(lumina.miembros + 0));
    printf("&lumina.miembros[1] = %p\n", (void *)&lumina.miembros[1]);
    printf("lumina.miembros + 1  = %p\n", (void *)(lumina.miembros + 1));

    return 0;
}

void mostrar(const Idol *i) {
    if (i == NULL) return;
    printf("Nombre: %s \n", i->nombre);
    printf("La popularidad: %d \n", i->popularidad);
    printf("energia: %d \n", i->energia);
    printf("energia maxima: %d \n", i->energia_Max);
    printf("fans: %d \n", i->fans);
}

int limitar(int valor, int minimo, int maximo) {
    if (valor < minimo) return minimo; 
    if (valor > maximo) return maximo;
    return valor;
}

void ensayar(Idol *i) {
    if (i == NULL) return;
    i->popularidad = limitar(i->popularidad + 5, 0, i->energia_Max);
    i->energia = limitar(i->energia - 20, 0, i->energia_Max);
}

void descansar(Idol *i) {
    if (i == NULL) return;
    i->energia = limitar(i->energia + 30, 0, i->energia_Max);
}

int esta_activa(const Idol *i) {
    if (i == NULL) return 0;
    return (i->energia > 0) ? 1 : 0;
}

void cambiar_por_valor(Idol jennie_val) {
    jennie_val.energia = 0;
    printf("Dentro de cambiar_por_valor: energia = %d\n", jennie_val.energia);
}

void cambiar_por_apuntador(Idol *jennie_ptr) {
    if (jennie_ptr == NULL) return;
    jennie_ptr->energia = 0;
    printf("Dentro de cambiar_por_apuntador: energia = %d\n", jennie_ptr->energia);
}

int colaboracion(Idol *a, Idol *b) {
    // Validación contra NULL y apuntadores repetidos (HU-09)[cite: 7, 8]
    if (a == NULL || b == NULL || a == b) {
        return 0;
    }

    a->popularidad = limitar(a->popularidad + 10, 0, a->energia_Max);
    a->energia = limitar(a->energia - 15, 0, a->energia_Max);

    b->popularidad = limitar(b->popularidad + 10, 0, b->energia_Max);
    b->energia = limitar(b->energia - 15, 0, b->energia_Max);

    printf("%s y %s hicieron una colaboracion :.\n", a->nombre, b->nombre);
    return 1;
}

void asignar_cancion(Idol *i, Cancion *c) {
    if (i != NULL) {
        i->cancion = c;
    }
}

int popularidad_total(const Idol *i) {
    if (i == NULL) return 0;
    int total = i->popularidad;
    if (i->cancion != NULL && i->cancion->vigencia > 0) {
        total += i->cancion->bonus;
    }
    return total;
}

int cambiar_lider(Grupo *g, Idol *nueva) {
    if (g == NULL || nueva == NULL) return 0;
    for (int k = 0; k < g->n; k++) {
        if (&g->miembros[k] == nueva) {
            g->lider = nueva;
            return 1;
        }
    }
    return 0;
}

void mostrar_grupo(const Grupo *g) {
    if (g == NULL) return;
    printf("=== GRUPO: %s ===\n", g->nombre);
    for (const Idol *p = g->miembros; p < g->miembros + g->n; p++) {
        mostrar(p);
    }
}

int contar_activas(const Grupo *g) {
    if (g == NULL || g->n == 0) return 0;
    int activas = 0;
    for (const Idol *p = g->miembros; p < g->miembros + g->n; p++) {
        if (esta_activa(p)) {
            activas++;
        }
    }
    return activas;
}

Idol *idol_mas_cansada(Grupo *g) {
    if (g == NULL || g->n <= 0) return NULL;
    Idol *mas_cansada = &g->miembros[0];
    for (Idol *p = g->miembros + 1; p < g->miembros + g->n; p++) {
        if (p->energia < mas_cansada->energia) {
            mas_cansada = p;
        }
    }
    return mas_cansada;
}

void dar_concierto(Grupo *g) {
    if (g == NULL) return;
    for (Idol *p = g->miembros; p < g->miembros + g->n; p++) {
        if (esta_activa(p)) {
            p->fans += popularidad_total(p) / 10;
            p->energia = limitar(p->energia - 25, 0, p->energia_Max);

            if (p->cancion != NULL && p->cancion->vigencia > 0) {
                p->cancion->vigencia--;
                if (p->cancion->vigencia == 0) {
                    printf("Aviso: La cancion '%s' ya no esta vigente.\n", p->cancion->nombre);
                }
            }
        }
    }
}

void mostrar_cancion_lider(const Grupo *g) {
    if (g == NULL) {
        printf("No existe el grupo.\n");
        return;
    }
    if (g->lider == NULL) {
        printf("El grupo no tiene lider.\n");
        return;
    }
    if (g->lider->cancion == NULL) {
        printf("La lider %s no tiene cancion.\n", g->lider->nombre);
        return;
    }
    printf("Cancion de la lider (%s): %s\n", g->lider->nombre, g->lider->cancion->nombre);
}

void preparar_presentacion(Grupo *g) {
    if (g == NULL) return;

    Idol *cansada = idol_mas_cansada(g);
    if (cansada != NULL) {
        descansar(cansada);
    }

    dar_concierto(g);

    printf("\n=== RESUMEN DE LA PRESENTACION ===\n");
    mostrar_grupo(g);
    printf("Integrantes activas: %d\n", contar_activas(g));
    mostrar_cancion_lider(g);
}
