# Archivos

* ¿para que utilizamos archivos?
    de manera resumida, para guardar informacionen forma permanente (en variables en memoria es temporaral)

* ¿que es el filesystem?

https://docs.kernel.org/filesystems/

    devices(lsblk -f)
    particiones(fdisk: device|unit|sector)(primaria/logica/swap)
    filesystems (mkfs.ext4 /dev/sda1)
    format
    mount/umount/findmnt            => mount root "/"
    archivos, directorios
    usuarios/grupos/permisos (chmod|chown)

* utilidades: 
	ls
    cat
	more
    touch
    rm
    file
	hexdump
	

* stdin, stdout y stderror

* acceso secuencial y acceso ramdom
