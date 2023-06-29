
int delete_rear3(node_t **head_dptr, int *retval)                                                                     
{                                                                                                                     
        
        assert(head_dptr);                                                                                            
        
        printf("%d@%s: head %p\n", __LINE__, __func__, *head_dptr);                                                   
        
        if ((*head_dptr) == NULL) {
                fprintf(stderr, "%s: empty list\n", __func__);                                                        
                return LIST_FAILURE;                                                                                  
        }                                                                                                             
        
        while ((*head_dptr)->next != NULL) {
                head_dptr = &((*head_dptr)->next);                                                                    
        }                                                                                                             
        
        *retval = (*head_dptr)->data;
        printf("%s: delete node %d\n", __func__, *retval);                                                            
        
        free((*head_dptr));                                                                                           
        
        *head_dptr = NULL;                                                                                            
                                                                                                                      
        
        printf("%d@%s: head %p\n", __LINE__, __func__, *head_dptr);                                                   
        return LIST_SUCCESS;                                                                                          
}  
