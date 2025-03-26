/*
*  ERC32_trap_handler
*
*  This file contains the trap handler for the ERC32.
*   
*  INPUT PARAMETERS:
*    vector  - vector number
*
*  OUTPUT PARAMETERS:
*    none
*
*  RETURN VALUE:
*    none
*/

#include <bsp.h>

void ERC32_trap_handler(rtems_vector_number vector)
{
    if ( SPARC_IS_INTERRUPT_TRAP( vector ) ) {
        uint32_t source;
    
        source = SPARC_INTERRUPT_TRAP_TO_SOURCE( vector );
    
        ERC32_Clear_interrupt( source );
        ERC32_Unmask_interrupt( source );
    }
}


