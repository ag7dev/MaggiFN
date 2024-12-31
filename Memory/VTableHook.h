#include <cstdint>  
#include <cstdlib>  
#include <iostream> 
namespace Hook
{
    class VTableHook
    {
    public:
        VTableHook() : originalVtable(nullptr), lastHookedFunctionAddress(0), lastHookedFunctionIndex(-1) {}

        
        template <typename FunctionType>
        bool Hook(void* instance, void* hookFunction, int vtableIndex, FunctionType* originalFunction)
        {
            
            originalVtable = *reinterpret_cast<uintptr_t**>(instance);

            
            if (lastHookedFunctionAddress && lastHookedFunctionIndex != -1)
            {
                if (lastHookedFunctionAddress == originalVtable[lastHookedFunctionIndex])
                {
                    return false; 
                }
            }

            
            void* originalFunctionPtr = reinterpret_cast<void*>(originalVtable[vtableIndex]);

            
            if (originalFunctionPtr != hookFunction)
            {
                
                int tableSize = 0;
                while (originalVtable[tableSize])
                {
                    ++tableSize;
                }

                
                uintptr_t* newVtable = reinterpret_cast<uintptr_t*>(std::malloc(tableSize * sizeof(uintptr_t)));

                
                std::memcpy(newVtable, originalVtable, tableSize * sizeof(uintptr_t));

                
                *originalFunction = reinterpret_cast<FunctionType>(originalFunctionPtr);

                
                newVtable[vtableIndex] = reinterpret_cast<uintptr_t>(hookFunction);

                
                *reinterpret_cast<uintptr_t**>(instance) = newVtable;

                
                lastHookedFunctionAddress = reinterpret_cast<uintptr_t>(hookFunction);
                lastHookedFunctionIndex = vtableIndex;

                return true;
            }

            return false; 
        }

        
        template <typename FunctionType>
        void Unhook(FunctionType originalFunction, void* instance)
        {
            
            if (originalVtable && lastHookedFunctionIndex != -1)
            {
                
                uintptr_t* currentVtable = *reinterpret_cast<uintptr_t**>(instance);

                
                currentVtable[lastHookedFunctionIndex] = reinterpret_cast<uintptr_t>(originalFunction);

                
                *reinterpret_cast<uintptr_t**>(instance) = originalVtable;

                
                std::free(currentVtable);

                
                lastHookedFunctionAddress = 0;
                lastHookedFunctionIndex = -1;
            }
        }

    private:
        uintptr_t* originalVtable;
        uintptr_t lastHookedFunctionAddress;
        int lastHookedFunctionIndex;
    };
}
