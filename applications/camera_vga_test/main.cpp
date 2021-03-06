#include "main.hpp"

void print_camera_config(Camera* cam) {
    printf("width changed to: %u\n", ((unsigned int) cam->config_get_width()));
    printf("heigh changed to: %u\n", ((unsigned int)  cam->config_get_height()));
    printf("start_row changed to: %u\n", ((unsigned int) cam->config_get_start_row()));
    printf("start_col changed to: %u\n", ((unsigned int) cam->config_get_start_column()));
    printf("row_size changed to: %u\n", ((unsigned int)  cam->config_get_row_size()));
    printf("col_size changed to: %u\n", ((unsigned int)  cam->config_get_column_size()));
    printf("row_mode changed to: %u\n", ((unsigned int)  cam->config_get_row_mode()));
    printf("col_mode changed to: %u\n", ((unsigned int)  cam->config_get_column_mode()));
    printf("exposure changed to: %u\n", ((unsigned int)  cam->config_get_exposure()));
    printf("h_blanking changed to: %u\n", ((unsigned int)  cam->config_get_h_blanking()));
    printf("v_blanking changed to: %u\n", ((unsigned int)  cam->config_get_v_blanking()));
    printf("red_gain changed to: %u\n", ((unsigned int)  cam->config_get_red_gain()));
    printf("blue_gain changed to: %u\n", ((unsigned int)  cam->config_get_blue_gain()));
    printf("green1_gain changed to: %u\n", ((unsigned int)  cam->config_get_green1_gain()));
    printf("green2_gain changed to: %u\n", ((unsigned int)  cam->config_get_green2_gain()));
}

int main(int argc, char **argv) {
    void *virtual_base;
    int fd;
    void *camera_virtual_address;

    // Open the device file for accessing the physical memory
    if ((fd = open("/dev/mem", (O_RDWR | O_SYNC))) == -1) {
        printf("ERROR: could not open \"/dev/mem\"...\n");
        return(1);
    }
    // Map the physical memory to the virtual address space. The base address
    // for the FPGA address map is stored in 'virtual_base'.
    virtual_base = mmap(NULL, HW_REGS_SPAN, (PROT_READ | PROT_WRITE),
                        MAP_SHARED, fd, HW_REGS_BASE);
    if( virtual_base == MAP_FAILED ) {
        printf( "ERROR: mmap() failed...\n" );
        close( fd );
        return( 1 );
    }
    // Virtual address of the camera registers.
    camera_virtual_address = (void*) ((uint8_t*)virtual_base + ((unsigned long) (AVALON_CAMERA_0_BASE) & (unsigned long) (HW_REGS_MASK)));

    //Initialize camera
    Camera cam(camera_virtual_address);

    //Write the col_size value written by the user in the avalon_camera registers
    if ( argc == 16) {
        cam.config_set_width(atoi(argv[1]));
        cam.config_set_height(atoi(argv[2]));
        cam.config_set_start_row(atoi(argv[3]));
        cam.config_set_start_column(atoi(argv[4]));
        cam.config_set_row_size(atoi(argv[5])) ;
        cam.config_set_column_size(atoi(argv[6]));
        cam.config_set_row_mode(atoi(argv[7]));
        cam.config_set_column_mode(atoi(argv[8]));
        cam.config_set_exposure(atoi(argv[9]));
        cam.config_set_h_blanking(atoi(argv[10]));
        cam.config_set_v_blanking(atoi(argv[11]));
        cam.config_set_red_gain(atoi(argv[12]));
        cam.config_set_blue_gain(atoi(argv[13]));
        cam.config_set_green1_gain(atoi(argv[14]));
        cam.config_set_green2_gain(atoi(argv[15]));
        cam.config_update();
        print_camera_config(&cam);
    }
    else if (argc == 2) {
        //show help message
        printf("HELP MESSAGE\n");
        printf("No arguments sets the default configuration\n");
        printf("Call with arguments to change the behaviour of the camera\n");
        printf("FORMAT: camera_vga_test width height start_row start_col row_size col_size row_mode col_mode exposure h_blanking v_blanking red_gain blue_gain green1_gain green2_gain\n");
        printf("EXAMPLE: ./camera_vga_test 640 480 0 0 1919 2559 17 17 1023 0 25 156 154 19 19\n");
    }
    else {
        // Set default values.
        cam.config_set_default();
        cam.config_update();
        print_camera_config(&cam);
    }

    // clean up the memory mapping and exit
    if (munmap( virtual_base, HW_REGS_SPAN ) != 0) {
        printf("ERROR: munmap() failed...\n");
        close(fd);
        return(1);
    }
    close(fd);
    return(0);
}
