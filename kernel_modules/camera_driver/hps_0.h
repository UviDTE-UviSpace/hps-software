#ifndef _ALTERA_HPS_0_H_
#define _ALTERA_HPS_0_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'soc_system' in
 * file './soc_system.sopcinfo'.
 */

/*
 * This file contains macros for module 'hps_0' and devices
 * connected to the following masters:
 *   h2f_axi_master
 *   h2f_lw_axi_master
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for device 'avalon_camera_0', class 'avalon_camera'
 * The macros are prefixed with 'AVALON_CAMERA_0_'.
 * The prefix is the slave descriptor.
 */
#define AVALON_CAMERA_0_COMPONENT_TYPE avalon_camera
#define AVALON_CAMERA_0_COMPONENT_NAME avalon_camera_0
#define AVALON_CAMERA_0_BASE 0x0
#define AVALON_CAMERA_0_SPAN 128
#define AVALON_CAMERA_0_END 0x7f

/*
 * Macros for device 'avalon_img_writer_rgbgray', class 'avalon_image_writer'
 * The macros are prefixed with 'AVALON_IMG_WRITER_RGBGRAY_'.
 * The prefix is the slave descriptor.
 */
#define AVALON_IMG_WRITER_RGBGRAY_COMPONENT_TYPE avalon_image_writer
#define AVALON_IMG_WRITER_RGBGRAY_COMPONENT_NAME avalon_img_writer_rgbgray
#define AVALON_IMG_WRITER_RGBGRAY_BASE 0x100
#define AVALON_IMG_WRITER_RGBGRAY_SPAN 64
#define AVALON_IMG_WRITER_RGBGRAY_END 0x13f

/*
 * Macros for device 'avalon_img_writer_gray', class 'avalon_image_writer'
 * The macros are prefixed with 'AVALON_IMG_WRITER_GRAY_'.
 * The prefix is the slave descriptor.
 */
#define AVALON_IMG_WRITER_GRAY_COMPONENT_TYPE avalon_image_writer
#define AVALON_IMG_WRITER_GRAY_COMPONENT_NAME avalon_img_writer_gray
#define AVALON_IMG_WRITER_GRAY_BASE 0x200
#define AVALON_IMG_WRITER_GRAY_SPAN 64
#define AVALON_IMG_WRITER_GRAY_END 0x23f

/*
 * Macros for device 'avalon_img_writer_binary', class 'avalon_image_writer'
 * The macros are prefixed with 'AVALON_IMG_WRITER_BINARY_'.
 * The prefix is the slave descriptor.
 */
#define AVALON_IMG_WRITER_BINARY_COMPONENT_TYPE avalon_image_writer
#define AVALON_IMG_WRITER_BINARY_COMPONENT_NAME avalon_img_writer_binary
#define AVALON_IMG_WRITER_BINARY_BASE 0x300
#define AVALON_IMG_WRITER_BINARY_SPAN 64
#define AVALON_IMG_WRITER_BINARY_END 0x33f


#endif /* _ALTERA_HPS_0_H_ */
