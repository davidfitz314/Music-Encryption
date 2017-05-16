# Music-Encryption
C++ Application

Special Libraries used for glut drawings and windows media.

Keys 1-7 are used for the piano and pressing them will play music and display a note on the screen.
The notes will keep adding on to the screen until they reach the screen boundaries.
Music uses a singular buffer style so only 1 note may be played at a time.

keys; 'e' and 'd' are the signals to begin encrypting or decrypting.
After pressing 'e' or 'd' the string of text generated from the musical notes will be used to create the caesarean cipher.

A caesarean cypher is used to change blocks of text from a file into encrypted or decrypted blocks of text. 
Each music note holds a different caesarian cypher of encrypting based on its musical frequency. 
By combing multiple notes a document can have multiple block encryptions.

example:
presing the keys '1', '2', and then '3' would create the string "DEF".
then pressing 'e' would send the string into the encrypt method.
the encrypt method will check the file size and divide it into x groups or in this case because of our string "DEF" it would be 3 groups.
the first group will be ciphered using the frequency modulated by alphabet size of the note 'D'.
the second group will be ciphered similarly but with the note 'E', and the third group is also similar.

#The output from the encryption will be a long string of text in a file as even spaces, return symbols, and some special characters have been ciphered.#

###the decrypt method follows a similar pattern as encrypt in order to be consistent.###
