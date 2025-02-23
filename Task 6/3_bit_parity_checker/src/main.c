#include <ch32v00x.h>
#include <debug.h>

#define LED_0 GPIO_Pin_0  // PC0
#define LED_1 GPIO_Pin_1  // PC1
#define LED_2 GPIO_Pin_2  // PC2
#define PARITY_LED GPIO_Pin_3 // PC3 (Parity indicator)

#define INPUT_0 GPIO_Pin_4  // PC4
#define INPUT_1 GPIO_Pin_5  // PC5
#define INPUT_2 GPIO_Pin_6  // PC6

void GPIO_Config(void);
int compute_parity(int num);

int main(void)
{
    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_Config();

    while (1)
    {
        // Read input states (PC4, PC5, PC6)
        int b0 = GPIO_ReadInputDataBit(GPIOC, INPUT_0);
        int b1 = GPIO_ReadInputDataBit(GPIOC, INPUT_1);
        int b2 = GPIO_ReadInputDataBit(GPIOC, INPUT_2);

        // Update LEDs based on input
        GPIO_WriteBit(GPIOC, LED_0, b0 ? Bit_SET : Bit_RESET);
        GPIO_WriteBit(GPIOC, LED_1, b1 ? Bit_SET : Bit_RESET);
        GPIO_WriteBit(GPIOC, LED_2, b2 ? Bit_SET : Bit_RESET);

        // Compute parity and update parity LED
        int parity = compute_parity(b0 + (b1 << 1) + (b2 << 2));
        GPIO_WriteBit(GPIOC, PARITY_LED, parity ? Bit_SET : Bit_RESET);
    }
}

// Configure GPIO for Inputs and Outputs
void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // Enable GPIOC clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Configure PC0, PC1, PC2, PC3 as Output (LEDs)
    GPIO_InitStructure.GPIO_Pin = LED_0 | LED_1 | LED_2 | PARITY_LED;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Configure PC4, PC5, PC6 as Input with Pull-Down Resistors
    GPIO_InitStructure.GPIO_Pin = INPUT_0 | INPUT_1 | INPUT_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; // Pull-down
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

// Compute Parity (Odd = 1, Even = 0)
int compute_parity(int num)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (num & (1 << i))
            count++;
    }
    return count % 2;
}
