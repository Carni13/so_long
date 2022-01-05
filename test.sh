!#bin/bash

make
make bonus

echo "error maps no bonus"
./so_long maps/error_test/no_collectible.ber
./so_long maps/error_test/no_exit.ber
./so_long maps/error_test/no_player.ber
./so_long maps/error_test/no_rectangle.ber
./so_long maps/error_test/no_valide_input.ber
./so_long maps/error_test/vide.ber
./so_long maps/error_test/dossier.ber
./so_long maps/error_test/too_short.ber
./so_long maps/error_test/too_thin.ber
./so_long maps/error_test/only_wall.ber
./so_long

./so_long_bonus maps/error/bonus_no_collectible.ber
./so_long_bonus maps/error/bonus_no_exit.ber
./so_long_bonus maps/error/bonus_no_player.ber
./so_long_bonus maps/error/bonus_no_rectangle.ber
./so_long_bonus maps/error/bonus_no_valide_input.ber
./so_long_bonus maps/error/bonus_only_wall.ber
./so_long_bonus maps/error/bonus_not_ber
./so_long_bonus maps/error_test/vide.ber
./so_long_bonus maps/error_test/dossier.ber
./so_long_bonus








