#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	returnAux = this->size;
    }

    return returnAux;
}


static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode=NULL;
	int i;
	int lenLL = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < lenLL){
		if(nodeIndex == 0){
			if(lenLL == 0){
				pNode = NULL;
			}else{
				pNode = this->pFirstNode;
			}
		}else{
				pNode = this->pFirstNode;
			for(i=0;i<nodeIndex;i++){
				pNode = pNode->pNextNode;
			}
		}
	}
    return pNode;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode;
    Node* auxNode;
    int lenLL = ll_len(this);
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= lenLL){
    	pNewNode = (Node*)malloc(sizeof(Node));
		if(pNewNode != NULL){
			if(nodeIndex == 0){
				pNewNode->pNextNode = this->pFirstNode;
				pNewNode->pElement = pElement;
				this->pFirstNode = pNewNode;
				this->size++;
				returnAux = 0;
			}
			else
			{
				auxNode = getNode(this,nodeIndex-1);
				if(auxNode != NULL){
					pNewNode->pNextNode = auxNode->pNextNode;
					pNewNode->pElement = pElement;
					auxNode->pNextNode = pNewNode;
					this->size++;
					returnAux = 0;
				}

			}
		}

    }

    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lenLL = ll_len(this);
    if(this != NULL){
    	if(!addNode(this,lenLL,pElement)){
    		returnAux = 0;
    	}
    }
    return returnAux;
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* bufferNode= NULL;
    int i;
    int lenLL = ll_len(this);
    if(this != NULL && index >= 0 && index < lenLL){
    		if(index==0){
    			bufferNode = getNode(this,0);
    			if(bufferNode != NULL){
					returnAux = bufferNode->pElement;
    			}else{
    				returnAux = NULL;
    			}
    		}else if (index == lenLL){
				bufferNode = getNode(this,lenLL);
				if(bufferNode != NULL){
					returnAux = bufferNode->pElement;
				}
    		}else{
				for(i=0;i<lenLL;i++){
					bufferNode = getNode(this,i);
					if(i==index && bufferNode != NULL){
						returnAux = bufferNode->pElement;
					}
				}
    		}
    }
    return returnAux;
}


int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *auxNode = NULL;
	int lenLL = ll_len(this);
	int i;
	if (this != NULL && index >= 0 && index < lenLL) {
			if (index == 0) {
				auxNode = getNode(this, 0);
				if(auxNode != NULL){
					auxNode->pElement = pElement;
					returnAux = 0;
				}
			} else if (index == lenLL-1) {
				auxNode = getNode(this, lenLL-1);
				if(auxNode != NULL){
					auxNode->pElement = pElement;
					returnAux = 0;
				}
			} else {
				for (i = 0; i <= index; i++) {
					auxNode = getNode(this, i);
					if(auxNode != NULL){
						if (i == index) {
							auxNode->pElement = pElement;
							returnAux = 0;
						}
					}
				}
			}

		}
	return returnAux;
}


int ll_remove(LinkedList* this,int index) //9
{
    int returnAux = -1;
    int i;
    int lenLL = ll_len(this); //10
    Node* auxNode = NULL;
    Node* auxNode2 = NULL;
    if(this != NULL && index >= 0 && index <lenLL){
    	if(index == 0){
    		if(lenLL == 0){
				auxNode = getNode(this,index);
				if(auxNode == NULL){
					returnAux = 0;
				}
    		}else{
    			auxNode2 = getNode(this,index+1);
    			this->pFirstNode = auxNode2;
    			this->size--;
				returnAux = 0;
    		}
    	}else {
    		auxNode = getNode(this,index+1);
    		if(auxNode != NULL){
    			for(i=0;i<lenLL;i++){ //se va este for
					if(i == index-1){
						auxNode2 = getNode(this,i);
						if(auxNode2 != NULL){
							auxNode2->pNextNode = auxNode;
							this->size--;
							returnAux = 0;
						}
					}

    			}
    		}else{
    			auxNode = getNode(this,index-1);
    			auxNode->pNextNode = NULL;
    			this->size--;
    			returnAux = 0;
    		}
    	}
    }


    return returnAux;
}


int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int lenLL = ll_len(this);
    if(this != NULL){
    	for(i=0;i<lenLL;i++){
    		ll_remove(this,i);
			returnAux = 0;
    	}
    }
    return returnAux;
}



int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    int i;
    int lenLL = ll_len(this);
    if(this != NULL){
    	for(i=0;i<lenLL;i++){
			auxNode = getNode(this,i);
			if(auxNode != NULL && auxNode->pElement == pElement){
				returnAux = i;
			}
    	}
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
	int lenLL = ll_len(this);
    int returnAux = -1;
    if(this != NULL){
    	if(lenLL == 0){
    		returnAux = 1;
    	}else{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
	int lenLL = ll_len(this);
    int returnAux = -1;
    Node* auxNode = NULL;
   // int i;
    if(this != NULL && index >= 0 && index <=lenLL){
    	auxNode = getNode(this, index);
    	if(auxNode == NULL){
			addNode(this,index,pElement);
			returnAux = 0;
    		}
        }
    return returnAux;
}


void* ll_pop(LinkedList* this,int index)//9
{
	int lenLL = ll_len(this);
    void* returnAux = NULL;
    Node* auxNode = NULL;
    int i;
    if(this != NULL && index >= 0 && index < lenLL){
    	for(i=0;i<lenLL;i++){
			auxNode = ll_get(this,i);
			if(i == index && auxNode != NULL){
				if(ll_remove(this,i)==0){
					returnAux = auxNode;
					break;
				}
			}
    	}
    }
    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL){
    	if(ll_indexOf(this,pElement) == -1){
    		returnAux = 0;
    	}else{
    		returnAux = 1;
    	}
    }

    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElement;
    int i;
    int lenLL2 = ll_len(this2);
    if(this != NULL && this2 != NULL){
    	if(lenLL2 == 0){
    		returnAux = 0;
    	}else{
			for(i=0;i<lenLL2;i++){
				auxElement = ll_get(this2,i);
				if(!ll_contains(this,auxElement)){
					returnAux = 0;
					break;
				}else{
					returnAux = 1;
				}
			}
    	}
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode = NULL;
    int lenLL = ll_len(this);
    int i;
    if(this != NULL && (from >=0 && from < lenLL) && (to > from && to <= lenLL)){
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL){
			for(i=from;i<=to;i++){
				auxNode = getNode(this,i);
				if(auxNode != NULL){
					addNode(cloneArray,i,auxNode->pElement);
				}
			}
    	}
    }
    return cloneArray;
}


LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int lenLL = ll_len(this);
    if(this != NULL){
    	cloneArray = ll_subList(this,0,lenLL);
    }
    return cloneArray;
}



int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	void *pElement1 = NULL;
	void *pElement2 = NULL;
	void *pAux = NULL;
	int lenLL = ll_len(this);
	int flagSwap = 1;
	int i;
	int r;
	if(this != NULL && pFunc != NULL && (order == 1 || order == 0) && lenLL > 0) {
		switch(order){
		    	case 1://ascendente
		    		do{
		    			flagSwap = 0;
		    			for(i=0;i<lenLL-1;i++){
		    				pElement1 = ll_get(this,i);
		    				pElement2 = ll_get(this,i+1);
							r = pFunc(pElement1,pElement2);
							if(r == 1){
								pAux = pElement1;
								ll_set(this,i,pElement2);
								ll_set(this,i+1,pAux);
								flagSwap = 1;
							}
						}
						lenLL--;
		    		}while(flagSwap);
					returnAux = 0;
		    		break;
		    	case 0://descendente
		    		do{
		    			flagSwap = 0;
						for(i=0;i<lenLL-1;i++){
							pElement1 = ll_get(this,i);
							pElement2 = ll_get(this,i+1);
							r = pFunc(pElement1,pElement2);
							if(r == -1){
								pAux = pElement1;
								ll_set(this,i,pElement2);
								ll_set(this,i+1,pAux);
								flagSwap = 1;
							}
						}
						lenLL--;
		    		}while(flagSwap);
					returnAux = 0;
		    		break;
		    	}
	}
	return returnAux;

}


LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*)){
	int i;
	void* auxElement;
	int lenLL = ll_len(this);
	if(this != NULL && pFunc != NULL){
			for(i=0;i<lenLL;i++){
				auxElement = ll_get(this, i);
				if(auxElement!= NULL){
					pFunc(auxElement);
					ll_set(this,i,auxElement);
				}
			}
	}
	return this;
}


int ll_count(LinkedList* this, int (*pFunc)(void* )){
	int auxCantidad = 0;
	int cantidadRetornada = 0;
	int i;
	int lenLL = ll_len(this);
	void* auxElement;
	if(this != NULL){
		for(i=0;i<lenLL;i++){
			auxElement = ll_get(this,i);
			auxCantidad = pFunc(auxElement);
			cantidadRetornada = cantidadRetornada + auxCantidad;
		}
	}
	return cantidadRetornada;
}
