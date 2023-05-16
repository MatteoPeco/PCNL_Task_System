Eng.

# Hololens graphic interface menu:

<p align="center">
  <img src="https://github.com/MatteoPeco/PCNL_Task_System/assets/94977542/937e08c4-a6fb-4bbe-a4f7-0f25c481c1f0" alt="menu" width="600px">
</p>

- __Scan button:__ the scan button, when pressed, activates the scanning feature of the hololens that allows the glasses to acquire the scanned QR codes code and position. After the 3 QR codes positions are acquired accurately the stop button that appears in place of the scan one makes the glasses visualize the model in correct position.

<p align="center">
  <img src="https://github.com/MatteoPeco/PCNL_Task_System/assets/94977542/b79576a7-f6bc-4ef0-b8da-2cd35f1caec3" alt="scanButton" width="400px">
</p>

- __Robot aligned button:__ the robot aligned button, when pressed, allows the user to change the robot control stage.
  - Robot control startegy: 
  
    _Stage1_: Needle free manipulation.
    
    _Stage2_: Robot stiffening, is the stage in which by pressing the Robot align button, the user sets a small stiffness along the needle direction.
    
    _Stage3_: Cartesian impedence controller implementation.
    
  __Control startegy demo video:__
  
     https://github.com/MatteoPeco/PCNL_Task_System/assets/94977542/748ac946-7058-4d55-b964-a1a99df154df 

      Observation: in the demo video the user is using an interface running in the unity play mode on the PC, the result is the same as the hololens application
    
   When the robot is in _Stage3_, its stage can be brought to _Stage1_ by simply pressing the __Cancel__ button appearing in place of the __Robot aligned__ button.
   
- __Lens button:__ the button with the lens icon must be pressed only when there is a tcp_ip server running in MATLAB on the machine with the IP indicated below the lens, this will send the orientation of the robot EE to the MATLAB script in order to compute the orientation error of the insertion procedure.

- __Gear button:__ the button with the gera icon must be pressed only when there is a tcp_ip server running in MATLAB on the machine with the IP indicated below the gear, this will send a request to the server to send the system calibration values. 
  - Systme calibration values: is the transformation matrix from the phantom to the robot to make the hololens visualize the holographic twin of the robot superimposed on the real one. The process of computation of the transformation is external to this repository and can be done with different strategies such as an hand-eye calibration by means of an optical tracker. 

- __Path control button__: when pressed toggles the path handle visibility by making the path interactable or not intercatable. 
#   
Ita.
# Menu dell'interfaccia grafica Hololens:
   
<p align="center">
  <img src="https://github.com/MatteoPeco/PCNL_Task_System/assets/94977542/937e08c4-a6fb-4bbe-a4f7-0f25c481c1f0" alt="menu" width="600px">
</p>

- __Pulsante scan:__ il pulsante di scansione, quando premuto, attiva la funzione di scansione delle Hololens che consente agli occhiali di scannerizzare i QR code e acquisire la loro posizione. Dopo che le posizioni dei 3 QR code sono state acquisite con precisione, il pulsante di stop che appare al posto di quello di scansione fa sì che gli occhiali visualizzino il modello nella posizione corretta.

<p align="center">
  <img src="https://github.com/MatteoPeco/PCNL_Task_System/assets/94977542/b79576a7-f6bc-4ef0-b8da-2cd35f1caec3" alt="scanButton" width="400px">
</p>

- __Pulsante Robot aligned:__ il pulsante di allineamento del robot, quando premuto, consente all'utente di cambiare la fase di controllo del robot.

  - Strategia di controllo del robot:

    Fase 1: Libera manipolazione del robot.

    Fase 2: Cambio della rigidità del robot, è la fase in cui premendo il pulsante di allineamento del robot, l'utente imposta un basso valore di resistenza al movimento   lungo la direzione dell'ago e alto nelle altre direzioni

    Fase 3: Implementazione del controllore di impedenza cartesiana.

__Video dimostrativo della strategia di controllo:__

  https://github.com/MatteoPeco/PCNL_Task_System/assets/94977542/748ac946-7058-4d55-b964-a1a99df154df 

      NB:  nel video dimostrativo l'utente sta utilizzando un'interfaccia sul PC, il risultato è lo stesso dell'applicazione hololens
      
Quando il robot si trova nella Fase 3, la sua fase può essere riportata alla Fase 1 semplicemente premendo il pulsante Cancel che appare al posto del pulsante Robot aligned.

- __Pulsante con icona della lente:__ il pulsante con l'icona della lente deve essere premuto solo quando è in esecuzione un server tcp_ip in MATLAB sulla macchina con l'IP indicato sotto la lente, questo invierà l'orientamento dell'end-effector (EE) del robot allo script MATLAB per calcolare l'errore di orientamento della procedura di inserzione.

- __Pulsante con icone dell'ingranaggio:__ il pulsante con l'icona dell'ingranaggio deve essere premuto solo quando è in esecuzione un server tcp_ip in MATLAB sulla macchina con l'IP indicato sotto l'ingranaggio, questo invierà una richiesta al server per inviare i valori di calibrazione del sistema.
  - Valori di calibrazione del sistema: è la matrice di trasformazione dal manichino al robot per far sì che gli occhiali Hololens visualizzino l'ologramma del robot sovrapposto a quello reale. Il processo di calcolo della trasformazione è esterno a questo repository e può essere effettuato con diverse strategie come l'hand-aye calibration mediante un tracker ottico.

- __Pulsante path control__: quando premuto, alterna la visibilità della maniglia del percorso olografico, rendendo il percorso interattivo o non interattivo.
