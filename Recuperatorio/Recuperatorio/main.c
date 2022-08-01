#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
}eVehiculo;


eVehiculo* newVehiculo();
int vehiculoSetId(eVehiculo* punt, int id);
int vehiculoSetMarca(eVehiculo* punt, char* marca);
int vehiculoSetTipo(eVehiculo* punt, int tipo);
int vehiculoSetPeso(eVehiculo* punt, int peso);
eVehiculo* newVehiculoParam(int id, char* marca, int tipo, float peso);
int controller_saveAsBinary(char* path, eVehiculo* vehiculo, int len);
int main()
{
    eVehiculo* vehiculo1= newVehiculo();
    if(vehiculo1==NULL)
    {
      printf("NO HAY LUGAR\n");
        system("pause");
        exit(1);
    }
    vehiculo1=newVehiculoParam(1234,"Aveo", 2, 3000);
    if(!controller_saveAsBinary("vehiculo.bin", vehiculo1, 1))
    {
        printf("DATOS GUARDADOS\n");
    }
    return 0;
}
eVehiculo* newVehiculo()
{
    eVehiculo* nuevoVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));
    if(nuevoVehiculo!=NULL)
    {
        nuevoVehiculo->id=0;
        strcpy(nuevoVehiculo->marca, "");
        nuevoVehiculo->tipo=0;
        nuevoVehiculo->peso=0;
    }
     return nuevoVehiculo;
}
int vehiculoSetId(eVehiculo* punt, int id)
{
    int todoOk=0;
    if(punt!=NULL&&id>0)
    {
            punt->id=id;
            todoOk=1;

    }
    return todoOk;
}
int vehiculoSetMarca(eVehiculo* punt, char* marca)
{
    int todoOk=0;
    if(punt!=NULL&& marca!=NULL &&strlen(marca)<20)
    {
        strcpy(punt->marca,marca);
        todoOk=1;
    }
    return todoOk;
}
int vehiculoSetTipo(eVehiculo* punt, int tipo)
{
    int todoOk=0;
    if(punt!=NULL&&tipo>0)
    {
            punt->tipo=tipo;
            todoOk=1;

    }
    return todoOk;
}
int vehiculoSetPeso(eVehiculo* punt, int peso)
{
    int todoOk=0;
    if(punt!=NULL&& peso>0)
    {
        punt->peso=peso;
        todoOk=1;
    }
    return todoOk;
}
eVehiculo* newVehiculoParam(int id, char* marca, int tipo, float peso)
{
    eVehiculo* nuevoVehiculo=newVehiculo();
    if(nuevoVehiculo!=NULL)
    {
       if(!(vehiculoSetId(nuevoVehiculo,id) &&
            vehiculoSetMarca(nuevoVehiculo,marca) &&
            vehiculoSetTipo(nuevoVehiculo,tipo) &&
            vehiculoSetPeso(nuevoVehiculo,peso)))
        {
            free(nuevoVehiculo);
            nuevoVehiculo=NULL;
        }
    }

    return nuevoVehiculo;
}

int controller_saveAsBinary(char* path, eVehiculo* vehiculo, int len)
{
    int todoOk=0;
    int cant;


    FILE* f= fopen(path, "wb");
    if(f==NULL)
    {
        printf("NO SE PUDO ABRIR\n");
    }

    for(int i=0; i<len; i++)
    {
        cant=fwrite(vehiculo, sizeof(eVehiculo),1,f);
        if(cant<1)
        {
            todoOk=1;
        }

    }
    fclose(f);



    return todoOk;
}
