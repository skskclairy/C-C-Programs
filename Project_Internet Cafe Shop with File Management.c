#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>


char* new_string(char* str)
{
    char* ret;
    ret = (char *) malloc(sizeof(char) * 255);
    strcpy (ret, str);
    return (ret);
}

int main ()
{
    char* services[255] = {"Document Printing", "Image Printing","Computer Rental", "Scanning", "Typing"};
    char ** name = services;
    char naming[255];
    int prices[255] = {2, 10, 15, 10,15};
    char* array_names[9];
    char inventory [255];
    char receipt[255];
    char sales_record[1255];
    char generating_report[255];
    char main_menu[255];
    char request[255];
    char product_history_1[255];
    char product_history_2[255];
    char product_history_3[255];
    char product_history_4[255];
    char product_history_5[255];
    char product_history_6[255];
    char product_history_7[255];
    char product_history_8[255];
    char product_history_9[255];
    char product_history_10[255];
    float array_amount[21] = {0};
    int array_quantity[20] = {0};
    float generating_array_amount[21] = {0};
    int generating_array_quantity[20] = {0};
    int month[10] = {0};
    int day[10] = {0};
    int hours[10] = {0};
    int order_no[10] = {1};
    float adv_price[10] = {0};
    float price;
    int service, quantity, t, num, pos;
    char decision, Y, N, char_service;
    int choice, choice_1, choice_2, choice_3, i, change, del_pos, process, generate;
    int size = 5;
    int order = 1;

    a:
    system("cls");
    printf("========================No Sleep Cafe========================\n\n");
    printf("\t\t\t-Main Menu-\n");
    printf("\n\t\t1. File Management\n");
    printf("\t\t2. Transaction\n");
    printf("\t\t3. Manage Advance request\n");
    printf("\t\t4. Generate Report\n");
    printf("\t\t5. Exit Program\n\n");
    printf("\t\tPlease Choose an option: ");
    scanf("%d", &choice);

        switch(choice)
    {
    case 1: //start of file management service
        system("cls");
    printf("========================No Sleep Cafe========================\n\n");
    printf("\t\t\t-File Management-\n");
    printf("\n\t\t1. ADD (New Service)\n");
    printf("\t\t2. EDIT (Edit new Service Price)\n");
    printf("\t\t3. DELETE (Delete Service)\n");
    printf("\t\t4. DISPLAY (All services)\n");
    printf("\t\t5. Go back to Main Menu\n\n");
    printf("\t\tPlease Choose an option: ");
    scanf("%d", &choice_1);

    if (choice_1 == 1) // adding of new service
    {
        system("cls");
        if (size == 10)
        {
            printf("Cannot add anymore Services!");
            getch();
            goto a;
        }
    printf("Enter service name to insert : ");
    scanf("%s", naming);
    printf("Enter service price to insert : ");
    scanf("%d", &num);

        /* Insert new element at given position and increment size */

        services[size] = new_string(naming);
        prices[size] = num;
        size++;
        free(services[size]);

        /* Print array after insert operation */
        printf("\nServices after adding ID %d: ", size);
        printf("\n\t      ID\tServices\tPrices\n");
        for(i=0; i<size; i++)
        {
            printf("\n%15d\t%-20s\t%d",i+1, services[i], prices[i]);
        }
    } //end of adding
    else if (choice_1 == 2) //editing prices
    {
        system("cls");
    printf("Enter the price change : ");
    scanf("%d", &change);
    printf("Enter service to be changed : ");
    scanf("%d", &pos);
        if(pos > size || pos <= 0)
    {
        printf("Invalid position! Please enter position between 1 to %d", size);
    }
    else
    {
        prices[pos-1] = change;
        printf("\nServices and Prices after editing ID %d: ", pos);
        printf("\n\t      ID\tServices\tPrices\n");
        for(i=0; i<size; i++)
        {
            printf("\n%15d\t%-20s\t%d",i+1, services[i], prices[i]);
        }
    }
    } // end of edit
     else if (choice_1 == 3) //deleting of products
     {
         system("cls");
        printf("Enter the element position to delete : ");
        scanf("%d", &del_pos);
            if(del_pos < 0 || del_pos > size)
            {
                printf("Invalid position! Please enter position between 1 to %d", size);
            }
                else
                {
                    for(i=del_pos-1; i<size-1; i++)
                    {
                        prices[i] = prices[i + 1];
                        services[i] = services[i + 1];
                    }
                    size--;

            printf("\nElements of array after delete are : ");
            printf("\n\t      ID\tServices\tPrices\n");
            for(i=0; i<size; i++)
            {
                printf("\n%15d\t%-20s\t%d",i+1, services[i], prices[i]);
            }
    }
     } // end of delete
     else if (choice_1 == 4) //displaying of services
     {
        system("cls");
            printf("========================No Sleep Cafe========================\n");
            printf("\n\t      ID\tServices\tPrices\n");
            for(i=0; i<size; i++)
            {
                printf("\n%15d\t%-20s\t%d",i+1, services[i], prices[i]);
            }
     }
     else if (choice_1 == 5)
     {
         goto a;
     }
     else
     {
        printf("Invalid service! (enter an integer 1-5)");
        break;
     }
    printf("\n\nPress any key to go to Main Menu!\n");
    getch();
    goto a; //end of file management
    case 2:
        b: // b if for transaction
    system("cls");
        FILE * product_inventory = fopen("File_1_Product_Inventory.txt", "w+");
        fprintf(product_inventory, "========================No Sleep Cafe========================");
        for(i=0; i<size; i++)
            {
                fprintf(product_inventory, "\n%15d\t%-20s\t%d",i+1, services[i], prices[i]);
            }
        rewind(product_inventory);
        while (fgets(inventory, 255, product_inventory)!= NULL)
        {
        printf ("%s", inventory);
        }
    printf("\n=============================================================");
    do
    {
        c: //commands for transaction
     printf("\n\nEnter type of service you want(Please input an integer): ");
    scanf ("%d", &service);
    if (service < 1)
    {
        printf("Invalid input! choose a positive integer.");
        goto c;
    }
    else if (service > size)
    {
        printf("Invalid input! Choose a correct product ID.");
        break;
        goto c;
    }
    service = service - 1;
    d:
    printf("\nNumber of Quantity (Amount): ");
    scanf ("%d", &quantity);
    if (quantity < 1)
    {
        printf("Invalid input! choose a positive integer.");
        goto d;
    }
    price = quantity * prices[service];
    printf("The Price are: %.2f\n", price);

    array_names[0] = "Types of Services";
    array_names[1] = "Quantity";
    array_names[2] = "Amount";
    array_names[3] = "Total sales: ";

    if (price == 0.00)
    {
        array_amount[service] = price;
        generating_array_amount[service] = array_amount[service];
        array_amount[20] += array_amount[service];
        generating_array_amount[20] += generating_array_amount[service];
    }
    else
    {
        array_amount[20] -= array_amount[service];
        generating_array_amount[20] -= generating_array_amount [service];
        array_amount[service] += price;
        generating_array_amount[service] += array_amount[service];
        array_amount[20] += array_amount[service];
        generating_array_amount[20] += generating_array_amount[service];
    }
    if (quantity == 0)
    {
        array_quantity[service] = quantity;
        generating_array_quantity[service] = array_quantity[service];
    }
    else
    {
        array_quantity[service] += quantity;
        generating_array_quantity[service] += array_quantity[service];
    }
    adv_price[order-1] = array_amount[20];

    while (decision != 'Y' || 'N')
    {
    printf ("\nWould you like another service? (Y/N) : ");
    scanf ("%s", &decision);
    if (decision == 'N')
    {
        printf ("\nYou've ended your service!\n\n");
        system("cls");
        break;
    }
    else if (decision == 'Y')
    {
        printf ("\nYou've chosen another service!\n\n");
        break;
    }
    else
    {
        printf ("Invalid service!\n");
    }
    }
    FILE * product_inventory_history = fopen("File_2_Product_History.txt", "a");
        fprintf (product_inventory_history,"%-17s", services [service]);
        fprintf (product_inventory_history,"%15d", quantity);
        fprintf (product_inventory_history,"%22.2f\n", price);

    if (service == 0)
    {
        FILE * product_inventory_history_1 = fopen("File_2.1.txt", "a");
        fprintf (product_inventory_history_1,"%-17s", services [service]);
        fprintf (product_inventory_history_1,"%15d", quantity);
        fprintf (product_inventory_history_1,"%22.2f\n", price);
        fclose(product_inventory_history_1);
    }
    else if (service == 1)
    {
        FILE * product_inventory_history_2 = fopen("File_2.2.txt", "a");
        fprintf (product_inventory_history_2,"%-17s", services [service]);
        fprintf (product_inventory_history_2,"%15d", quantity);
        fprintf (product_inventory_history_2,"%22.2f\n", price);
            fclose(product_inventory_history_2);
    }
    else if (service == 2)
    {
            FILE * product_inventory_history_3 = fopen("File_2.3.txt", "a");
        fprintf (product_inventory_history_3,"%-17s", services [service]);
        fprintf (product_inventory_history_3,"%15d", quantity);
        fprintf (product_inventory_history_3,"%22.2f\n", price);
            fclose(product_inventory_history_3);
    }
    else if (service == 3)
    {
            FILE * product_inventory_history_4 = fopen("File_2.4.txt", "a");
        fprintf (product_inventory_history_4,"%-17s", services [service]);
        fprintf (product_inventory_history_4,"%15d", quantity);
        fprintf (product_inventory_history_4,"%22.2f\n", price);
            fclose(product_inventory_history_4);
    }
    else if (service == 4)
    {
            FILE * product_inventory_history_5 = fopen("File_2.5.txt", "a");
        fprintf (product_inventory_history_5,"%-17s", services [service]);
        fprintf (product_inventory_history_5,"%15d", quantity);
        fprintf (product_inventory_history_5,"%22.2f\n", price);
            fclose(product_inventory_history_5);
    }
    else if (service == 5)
    {
            FILE * product_inventory_history_6 = fopen("File_2.6.txt", "a");
        fprintf (product_inventory_history_6,"%-17s", services [service]);
        fprintf (product_inventory_history_6,"%15d", quantity);
        fprintf (product_inventory_history_6,"%22.2f\n", price);
            fclose(product_inventory_history_6);
    }
    else if (service == 6)
    {
            FILE * product_inventory_history_7 = fopen("File_2.7.txt", "a");
        fprintf (product_inventory_history_7,"%-17s", services [service]);
        fprintf (product_inventory_history_7,"%15d", quantity);
        fprintf (product_inventory_history_7,"%22.2f\n", price);
            fclose(product_inventory_history_7);
    }
    else if (service == 7)
    {
            FILE * product_inventory_history_8 = fopen("File_2.8.txt", "a");
        fprintf (product_inventory_history_8,"%-17s", services [service]);
        fprintf (product_inventory_history_8,"%15d", quantity);
        fprintf (product_inventory_history_8,"%22.2f\n", price);
            fclose(product_inventory_history_8);
    }
    else if (service == 8)
    {
            FILE * product_inventory_history_9 = fopen("File_2.9.txt", "a");
        fprintf (product_inventory_history_9,"%-17s", services [service]);
        fprintf (product_inventory_history_9,"%15d", quantity);
        fprintf (product_inventory_history_9,"%22.2f\n", price);
            fclose(product_inventory_history_9);
    }
    else if (service == 9)
    {
            FILE * product_inventory_history_10 = fopen("File_2.10.txt", "a");
        fprintf (product_inventory_history_10,"%-17s", services [service]);
        fprintf (product_inventory_history_10,"%15d", quantity);
        fprintf (product_inventory_history_10,"%22.2f\n", price);
            fclose(product_inventory_history_10);
    }
    FILE * sales_inventory_report = fopen ("File_3_Sales_Inventory_Report.txt", "w");
        fprintf (sales_inventory_report, "Sales Inventory Report\n\n");
        fprintf (sales_inventory_report, "%17s%17s%17s\n\n", array_names[0], array_names[1], array_names[2]);
        for(i=0; i<size; i++)
        {
            fprintf (sales_inventory_report, "%-17s%17d%17.2f\n", services[i], array_quantity[i], array_amount[i]);
        }
        fprintf (sales_inventory_report, "%34s%17.2f\n", array_names[3], array_amount[20]);

        FILE * generating_sales_inventory_report = fopen ("File_4_Generating_Sales_Inventory_Report_.txt", "w");
        fprintf (generating_sales_inventory_report, "Sales Inventory Report\n\n");
        fprintf (generating_sales_inventory_report, "%17s%17s%17s\n\n", array_names[0], array_names[1], array_names[2]);
        for(i=0; i<size; i++)
        {
            fprintf (generating_sales_inventory_report, "%-17s%17d%17.2f\n", services[i], generating_array_quantity[i], generating_array_amount[i]);
        }
        fprintf (generating_sales_inventory_report, "%34s%17.2f\n", array_names[3], generating_array_amount[20]);
    fclose(product_inventory_history);
    fclose(product_inventory);
    fclose(sales_inventory_report);
    fclose(generating_sales_inventory_report);
    }
    while (decision == 'Y');
    {
        printf ("Printing you the sales report...\n\n");
        FILE * sales_inventory_report = fopen ("File_3_Sales_Inventory_Report.txt", "r");
    while (fgets(receipt, 255, sales_inventory_report)!= NULL)
    {
        printf ("%s\n", receipt);
    }
    for(i=0; i<size; i++)
    {
        array_quantity[i] = 0;
        array_amount[i] = 0;
        array_amount[20] = 0;
    }
    printf ("Prepared by: Angelo Andres, Frenzy Royse Reyes, Zarene Claire Guingab & John Ross Ferrancullo\n");
    if (choice == 3)
    {
        goto f;
    }
    time(&t);
    printf ("Date prepared: %s\n", ctime(&t));
    }
    printf("\nPress any key to go to Main Menu!\n");
    getch();
    goto a; // a is for main menu / end of transaction
        break;
    case 3:
        e: // manage advance request service
            system("cls");
    printf("========================No Sleep Cafe========================\n\n");
    printf("\t\t\t-Manage Advance Request-\n");
    printf("\n\t\t1. Advance service Request\n");
    printf("\t\t2. Process Service Request\n");
    printf("\t\t3. Go back to Main Menu\n\n");
    printf("\t\tPlease Choose an option: ");
    scanf("%d", &choice_3);

    if (choice_3 == 1) //requesting of order
    {
        order_no[order-1] = order;
        printf("\nOrder Requested! Your Order number is: " );
        printf("\nRequest Order number: #%d", order_no[order-1]);
        printf("\nPress any key to Continue!");
        getch();
        goto b;
        f:
        printf ("\nOrder number: #%d", order);
        printf("\nEnter Pick up date: (M/D)");
        printf("\nEnter Month: ");
        scanf("%d", &month[order-1]);
        printf("You picked the month: %d", month[order-1]);
        printf("\nEnter Day: ");
        scanf("%d", &day[order-1]);
        printf("You picked the day: %d", day[order-1]);
        printf("\nEnter Military Time(ex.__:00): ");
        scanf("%d", &hours[order-1]);
        printf("You chose the time: %-d :00", hours[order-1]);
        printf("\nTotal price of the transaction: %.2f", adv_price[order-1]);
        printf("\nOrder Requested!--");
        order++;
        printf("\nPress any key to go to Main Menu!\n");
        getch();
        goto a;
    } //end
    else if (choice_3 == 2) // processing of request order
    {
        system("cls");
        FILE * service_request = fopen("File_5_Service_Request.txt", "w+");
        fprintf(service_request, "========================No Sleep Cafe========================\n");
        fprintf(service_request,"No.\tID\tMonth / Day\t\tTime\t\tTotal Price");
        for(i=0; i<order-1; i++)
            {
                fprintf(service_request, "\n%d\t#%d%10d / %-d%14d:00%17.2f", i+1, order_no[i], month[i], day[i], hours[i], adv_price[i]);
            }
        rewind(service_request);
        while (fgets(request, 255, service_request)!= NULL)
        {
        printf ("%s", request);
        }
    printf("\n=============================================================");
        printf("\nEnter the No. to process : ");
        if (order == 1)
        {
            printf("No service to process yet!\n");
            printf("Go back to Manage Advance service");
            getch();
            goto e;
        }
        scanf("%d", &process);
            printf("Order No. #%d: Completed!\nTotal Price: %.2f", order_no[process-1], adv_price[process-1]);
            if(process < 0 || process > order)
            {
                printf("Invalid position! Please enter position between 1 to %d", order);
            }
                else
                {
                    for(i=process-1; i<order-1; i++)
                    {
                        order_no[i] = order_no[i+1];
                        month[i] = month[i + 1];
                        day[i] = day[i + 1];
                        hours[i] = hours[i + 1];
                        adv_price[i] = adv_price[i + 1];
                    }
                    order--;
                }
    printf("\n\nPress any key to go to Manage Advance Request!\n");
    getch(); // end
    goto e;
    }
    else if (choice_3 == 3) // going back to main menu
    {
        goto a;
    }
    else
    {
        printf("Invalid service! (enter an integer 1-3)");
        printf("Go back to Main Menu");
        goto a;
        break;
    }
        break; // end of manage advance request service
    case 4:
        g: // generate report service
    system("cls");
    printf("========================No Sleep Cafe========================\n\n");
    printf("\t\t\t-Generate Report-\n");
    printf("\n\t\t1. Generate Sales Record\n");
    printf("\t\t2. Generate Sales Inventory\n");
    printf("\t\t3. Generate Sales per Service\n");
    printf("\t\t4. Go back to Main Menu\n\n");
    printf("\t\tPlease Choose an option: ");
    scanf("%d", &choice_2);

    if(choice_2 == 1) // generate sales record
    {
            system("cls");
            printf("Sales Record\n");
    FILE * product_inventory_history = fopen("File_2_Product_History.txt", "r");
        while (fgets(sales_record, 1255, product_inventory_history)!= NULL)
        {
        printf ("%s", sales_record);
        }
    printf("\n\nPress any key to go to Generate Report!\n");
    getch();
    goto g;
    }
    else if (choice_2 == 2) //generate sales per inventory
    {
            system("cls");
        FILE * generating_sales_inventory_report = fopen ("File_4_Generating_Sales_Inventory_Report_.txt", "r");
        while (fgets(generating_report, 255, generating_sales_inventory_report)!= NULL)
        {
        printf ("%s", generating_report);
        }
    }
    else if (choice_2 == 3) // generate sales per service
    {
            system("cls");
        FILE * product_inventory = fopen("File_1_Product_Inventory.txt", "w+");
        fprintf(product_inventory, "========================No Sleep Cafe========================");
        for(i=0; i<size; i++)
            {
                fprintf(product_inventory, "\n%15d\t%-20s\t",i+1, services[i]);
            }
        rewind(product_inventory);
        while (fgets(inventory, 255, product_inventory)!= NULL)
        {
        printf ("%s", inventory);
        }
        h:
    printf("\n=============================================================");
    printf("\nSelect Service to Generate: ");
    scanf("%d", &generate);
    printf("Sales Record: %d\n", generate);
        FILE * product_inventory_history_1 = fopen("File_2.1.txt", "r");
        FILE * product_inventory_history_2 = fopen("File_2.2.txt", "r");
        FILE * product_inventory_history_3 = fopen("File_2.3.txt", "r");
        FILE * product_inventory_history_4 = fopen("File_2.4.txt", "r");
        FILE * product_inventory_history_5 = fopen("File_2.5.txt", "r");
        FILE * product_inventory_history_6 = fopen("File_2.6.txt", "r");
        FILE * product_inventory_history_7 = fopen("File_2.7.txt", "r");
        FILE * product_inventory_history_8 = fopen("File_2.8.txt", "r");
        FILE * product_inventory_history_9 = fopen("File_2.9.txt", "r");
        FILE * product_inventory_history_10 = fopen("File_2.10.txt", "r");

    if (generate == 1) // displaying of every file
    {
        while (fgets(product_history_1, 255, product_inventory_history_1)!= NULL)
        {
        printf ("%s", product_history_1);
        }
	}
    else if (generate == 2)
        while (fgets(product_history_2, 255, product_inventory_history_2)!= NULL)
        {
        printf ("%s", product_history_2);
        }
    else if (generate == 3)
        while (fgets(product_history_3, 255, product_inventory_history_3)!= NULL)
        {
        printf ("%s", product_history_3);
        }
    else if (generate == 4)
        while (fgets(product_history_4, 255, product_inventory_history_4)!= NULL)
        {
        printf ("%s", product_history_4);
        }
    else if (generate == 5)
        while (fgets(product_history_5, 255, product_inventory_history_5)!= NULL)
        {
        printf ("%s", product_history_5);
        }
    else if (generate == 6)
        while (fgets(product_history_6, 255, product_inventory_history_6)!= NULL)
        {
        printf ("%s", product_history_6);
        }
    else if (generate == 7)
        while (fgets(product_history_7, 255, product_inventory_history_7)!= NULL)
        {
        printf ("%s", product_history_7);
        }
    else if (generate == 8)
        while (fgets(product_history_8, 255, product_inventory_history_8)!= NULL)
        {
        printf ("%s", product_history_8);
        }
    else if (generate == 9)
        while (fgets(product_history_9, 255, product_inventory_history_9)!= NULL)
        {
        printf ("%s", product_history_9);
        }
    else if (generate == 10)
        while (fgets(product_history_10, 255, product_inventory_history_10)!= NULL)
        {
        printf ("%s", product_history_10);
        }
        else
        {
            printf("Invalid Service!");
            goto h;
        }
        printf("\n\nPress any key to go to Generate Report!\n");
        getch();
        goto g;
    }
    else if(choice_2 == 4) // back to main menu
    {
         goto a;
    }
    else
    {
        printf("Invalid service! (enter an integer 1-4)");
        printf("Go back to Main Menu");
        getch();
        goto a;
        break;
    }
        printf("\nPress any key to go to Main Menu!\n");
        getch();
        goto a;
        break;
    case 5:
        printf("\n System Out, Thank You! \n");
        return 0;
        break;
    default:
        printf("Invalid service! (enter an integer 1-5)");
        break;
    }
} // end program
