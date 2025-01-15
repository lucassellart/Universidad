#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATERIAS 4

typedef struct
{

    char nombre[50];
    int edad;
    int materias[MATERIAS];

}alumno;

void cargaEstudiante(alumno *);

void guardaEstudianteArchivos(alumno *);

int validaApertura(FILE *);

void consultarAlumno();

int main()
{
    alumno * alumno1 = malloc(sizeof(alumno));

    cargaEstudiante(alumno1);

    guardaEstudianteArchivos(alumno1);

    consultarAlumno();

    return 0;
}

void cargaEstudiante(alumno * est)
{
    printf("Ingrese su nombre:\n>");
    scanf("%s",est->nombre);
    printf("Ingrese su edad:\n>");
    scanf("%i",&est->edad);

    printf("Ingrese las materias a las que se desea inscribir:\n");
    printf("Opciones:");
    printf("\n1 = algebra.");
    printf("\n2 = logica.");
    printf("\n3 = informatica.");
    printf("\n4 = algoritmos.");

    for(int i=0; i<MATERIAS; i++)
    {
        printf("\n(materia%i) 1=inscribirse 0=no inscribirse \n>",i+1);
        scanf("%i",&est->materias[i]);

        if(est->materias[i] == 1)
        {
            est->materias[i] = i+1; //siempre me dijeron que mientras ande no se toca, puedo defender esta linea a capa y espada. (con esto ajusto para que valga lo que se corresponde con el witch)
                    //se guarda el valor que se corresponde con el valor "clave" de la materia.
        }
        else
        {
            est->materias[i] = 0;
        }
    }

}

void guardaEstudianteArchivos(alumno * alumnoCargado)
{
    for(int i=0; i<MATERIAS; i++)
    {
        switch(alumnoCargado->materias[i])
        {
        case 1:
            FILE * fileAlgebra = fopen("algebra.txt","wb");

            validaApertura(fileAlgebra);

            fwrite(alumnoCargado,sizeof(alumno),1,fileAlgebra);

            fclose(fileAlgebra);
            break;

        case 2:
            FILE * fileLogica = fopen("logica.txt","wb");

            validaApertura(fileLogica);

            fwrite(alumnoCargado,sizeof(alumno),1,fileLogica);

            fclose(fileLogica);
            break;

        case 3:
            FILE * fileInformatica = fopen("informatica.txt","wb");

            validaApertura(fileInformatica);

            fwrite(alumnoCargado,sizeof(alumno),1,fileInformatica);

            fclose(fileInformatica);
            break;

        case 4:
            FILE * fileGrafos = fopen("grafos.txt","wb");

            validaApertura(fileGrafos);

            fwrite(alumnoCargado,sizeof(alumno),1,fileGrafos);

            fclose(fileGrafos);
            break;
        case 0:
                break;
        default:
            printf("Erroneamente se cargo una materia que no existe.");
            break;
        }
    }
}

int validaApertura(FILE * archivo)
{
    if(archivo == NULL)
    {
        printf("Error al abrir el archivo para guardar los datos.");
        return 1;
    }
}

void consultarAlumno()
{
    alumno * est = malloc(sizeof(alumno));

    char alumnoBuscado[50];

    printf("\nIngrese el nombre del alumno buscado:\n>");
    scanf("%s",alumnoBuscado);

    int materiaBuscada = 0;

    printf("Ingrese la materia a la cual desea saber si el alumno esta incripto:\n");
    printf("Opciones:");
    printf("\n1 = algebra.");
    printf("\n2 = logica.");
    printf("\n3 = informatica.");
    printf("\n4 = algoritmos.");
    printf("\n>");
    scanf("%i",&materiaBuscada);

    int banderaEncontrado = 0;

    switch(materiaBuscada)
    {
    case 1:
        FILE * fileAlgebra = fopen("algebra.txt","rb");

        validaApertura(fileAlgebra);

        while( fread(est,sizeof(alumno),1,fileAlgebra) == 1)
        {
            printf("%s",est->nombre);
            if(strcmp(est->nombre , alumnoBuscado) == 0)
            {
                printf("\nEl alumno %s esta inscripto a algebra.\n",alumnoBuscado);
                banderaEncontrado = 1;
                break;
            }
        }
        if(!banderaEncontrado)
            printf("El alumno %s no esta inscripto a algebra.",alumnoBuscado);

        fclose(fileAlgebra);
        break;

    case 2:
        FILE * fileLogica = fopen("algebra.txt","rb");

        validaApertura(fileLogica);

        while(fread(est,sizeof(alumno),1,fileLogica) == 1)
        {
            if(strcmp(est->nombre , alumnoBuscado) == 0)
            {
                printf("\nEl alumno %s esta inscripto a algebra.\n",alumnoBuscado);
                banderaEncontrado = 1;
                break;
            }
        }
        if(!banderaEncontrado)
            printf("El alumno %s no esta inscripto a algebra.",alumnoBuscado);

        fclose(fileLogica);
        break;

    case 3:
        FILE * fileInformatica = fopen("informatica.txt","rb");

        validaApertura(fileInformatica);

        while( fread(est,sizeof(alumno),1,fileInformatica) == 1)
        {
            if(strcmp(est->nombre , alumnoBuscado) == 0)
            {
                printf("\nEl alumno %s esta inscripto a informatica.\n",alumnoBuscado);
                banderaEncontrado = 1;
                break;
            }
        }
        if(!banderaEncontrado)
            printf("El alumno %s no esta inscripto a informatica.",alumnoBuscado);

        fclose(fileInformatica);
        break;

    case 4:
        FILE * fileGrafos = fopen("grafos.txt","rb");

        validaApertura(fileGrafos);

        while( fread(est,sizeof(alumno),1,fileGrafos) == 1)
        {
            if(strcmp(est->nombre , alumnoBuscado) == 0)
            {
                printf("\nEl alumno %s esta inscripto a grafos.\n",alumnoBuscado);
                banderaEncontrado = 1;
                break;
            }
        }
        if(!banderaEncontrado)
            printf("El alumno %s no esta inscripto a informatica.",alumnoBuscado);

        fclose(fileGrafos);
        break;

    default:
        printf("No existe la materia buscada.");
        break;
    }
}
