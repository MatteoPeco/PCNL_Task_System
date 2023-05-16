NB: La versione in italiano si trova nella seconda metà dei file README della repository
#
Eng:
# Augmented Reality and Robot-Assisted Needle Insertion for Percutaneous Nephrolithotomy Task
<p align="center">
  <img src="./images/logoPolitecnicoNearlab.PNG" alt="Alt Text">
</p>

    Main authors: Matteo Pecorella, Junling Fu.
 
***
This repository contains the implementation of an Augmented Reality (AR) visualization-based path planning and navigation system for Percutaneous Nephrolithotomy (PCNL) with robotic-guided needle insertion. The aim of this project is to improve the PCNL procedure by reducing the surgeon's workload and achieving better insertion accuracy.

<p align="center">
  <img src="./images/SystemCoverWithLabels.png" alt="Alt Text" style="width: 600px;">
</p>

## Introduction
PCNL is considered the gold standard for treating patients with kidney stones larger than 20mm. It is a minimally invasive surgical procedure that involves inserting a nephroscope into the kidney to break up the stone and suction out the pieces. However, there are limitations to the procedure, including the surgeon's workload and challenges in precise needle insertion.

To address these limitations, this project proposes an AR-based system that provides real-time visualization and guidance during the PCNL procedure. The system utilizes pre-operative MRI or CT scan images to generate a 3D model and plan the desired path. During the intra-operative phase, the surgeon uses an Optical See Through - Head Mounted Display (OST-HMD) to perform real-time registration and visualize the 3D model hologram superimposed on the patient. The surgeon can validate and adjust the pre-planned path based on intra-operative images and is assisted by a serial robot for needle insertion.

## System Architecture
The proposed system architecture is divided into two phases: the pre-operative and intra-operative phases.

During the pre-operative phase:
1. MRI or CT scan images of the patient are acquired 
2. The images are segmented to generate a 3D model.
3. The desired path for needle insertion is planned based on the 3D model.

During the intra-operative phase:

4. The surgeon uses an OST-HMD to perform real-time registration 
5. The surgeon visualize the 3D model hologram superimposed on the patient and validates and adjusts the pre-planned path based on intra-operative images.
6. A serial robot assists the surgeon during needle insertion, following the pre-planned path.

The system relies on an Optical Tracker (OT) for system calibration and to measure the accuracy. It also utilizes QR code markers and fiducial markers on a phantom model   for accurate registration.

<p align="center">
  <img src="./images/SystemArchitecture.png" alt="Alt Text">
</p>

## Demo video

Preview:

https://github.com/MatteoPeco/PCNL_Task_System/assets/94977542/232d6fe9-3dc1-4e2f-8acd-c8fc2c684b77


Complete demo video at:  

<p align="center">
  https://drive.google.com/file/d/1Bb8xHS0bwqG7Qv82C1dTycltremJzU55/view?usp=share_link
</p>

## Experimental Validation
The system's performance and usability were evaluated through experiments involving 14 users with no prior surgery or AR headset experience. The users performed the needle insertion procedure using four different system setups: screen-based manual setup (SM), AR-based manual setup (AM), screen-based + robot assistance setup (SA), and AR-based + robot assistance setup (AA). Each setup was repeated three times, and the users' insertion accuracy was measured.

The performance metrics shown below include:

- Insertion procedure accuracy: Assessing the accuracy of needle insertion along the pre-planned path.
- Usability: Gathering qualitative feedback through a questionnaire to evaluate the user's workload during the tasks.

## Performances:

- Insertion procedure accuracy: 
  - Translation error from the target (median ± std.) -> 3.2 ± 1.4 mm 
  - Orientation error with respect to the pre-planned path (median ± std.) ->  1.2 ± 0.9° 
- Usability: The qualitative feedback gathered through the user questionnaire shown that the proposed system (AA) had the *__highest__* usability compared to all the other setups, including the setup emulating the operating room (SM).

## Repository Structure
- src/: Contains the unity project to be uploaded in the Hololens2 and the ROS catkin_ws for the robot control.
- images/: Contains the images of the repository.
- docs/: Contains the user manual for the system and a more detailed explaination of the robot control strategy.
- videos/: Includes demo videos showcasing the system in action.
#
Ita:
# Sistema basato su Realtà Aumentata e Assistenza Robotica per la procedura di inserzione di una Nefrolitotrissia Percutanea
<p align="center">
  <img src="./images/logoPolitecnicoNearlab.PNG" alt="Alt Text">
</p>

    Main authors: Matteo Pecorella, Junling Fu.
 
***
Questa repository contiene l'implementazione di un sistema di pianificazione e navigazione chirurgica basato sulla Realtà Aumentata (RA) per la Nefrolitotrissia Percutanea (PCNL) in cui la fase di inserzione è supportata da un robot. L'obiettivo di questo progetto è migliorare la procedura PCNL riducendo il carico di lavoro del chirurgo e ottenendo una maggiore accuratezza nell'inserzione.

<p align="center">
  <img src="./images/SystemCoverWithLabels.png" alt="Alt Text" style="width: 600px;">
</p>

## Introduzione
La PCNL è considerata lo standard di riferimento per il trattamento dei pazienti con calcoli renali di dimensioni superiori a 20 mm. Si tratta di una procedura chirurgica minimamente invasiva che prevede l'inserimento di un nefroscopio nel rene per frammentare il calcolo e aspirare i frammenti. Tuttavia, ci sono limitazioni alla procedura, tra cui il carico di lavoro del chirurgo e la comlessità nel raggiungere un'inserzione accurata.

Per affrontare queste limitazioni, questo progetto propone un sistema basato su RA e assistenza robotica per visualizzare e guidare in tempo reale la procedura PCNL. Il sistema utilizza immagini pre-operatorie di risonanza magnetica (MRI) o tomografia computerizzata (CT) per generare un modello 3D e pianificare il percorso d'inserzione desiderato. Durante la fase intra-operatoria, il chirurgo utilizza un visore "Optical See Through - Head Mounted Display" (OST-HMD) per effettuare la registrazione in tempo reale e visualizzare l'ologramma del modello 3D sovrapposto al paziente. Il chirurgo può convalidare e regolare il percorso d'inserzione in base alle immagini intra-operatorie ed è assistito da un robot seriale per l'inserimento dell'ago.

## Architettura del Sistema
Il sistema ha un'architettura è divisa in due fasi: la fase pre-operatoria e la fase intra-operatoria.

Durante la fase pre-operatoria:

Vengono acquisite le immagini di risonanza magnetica (MRI) o tomografia computerizzata (CT) del paziente.
Le immagini vengono segmentate per generare un modello 3D.
Viene pianificato il percorso desiderato per l'inserimento dell'ago basato sul modello 3D.
Durante la fase intra-operatoria:

Il chirurgo utilizza un visore montato sulla testa con tecnologia di trasparenza ottica per effettuare la registrazione in tempo reale.
Il chirurgo visualizza l'ologramma del modello 3D sovrapposto al paziente e convalida e regola il percorso pre-pianificato in base alle imm
agini intra-operatorie.
6. Un robot seriale assiste il chirurgo durante l'inserimento dell'ago, seguendo il percorso pre-pianificato.

Il sistema si basa su un sistema di tracciamento ottico (OT) per la calibrazione del sistema e per misurare l'accuratezza. Utilizza inoltre marcatori QR code e marcatori fiduciali su un modello fantoccio per una registrazione accurata.

<p align="center">
  <img src="./images/SystemArchitecture.png" alt="Alt Text">
</p>

## Demo video

Preview:

https://github.com/MatteoPeco/PCNL_Task_System/assets/94977542/232d6fe9-3dc1-4e2f-8acd-c8fc2c684b77


Complete demo video at:  

<p align="center">
  https://drive.google.com/file/d/1Bb8xHS0bwqG7Qv82C1dTycltremJzU55/view?usp=share_link
</p>

## Experimental Validation
The system's performance and usability were evaluated through experiments involving 14 users with no prior surgery or AR headset experience. The users performed the needle insertion procedure using four different system setups: screen-based manual setup (SM), AR-based manual setup (AM), screen-based + robot assistance setup (SA), and AR-based + robot assistance setup (AA). Each setup was repeated three times, and the users' insertion accuracy was measured.

The performance metrics shown below include:

- Insertion procedure accuracy: Assessing the accuracy of needle insertion along the pre-planned path.
- Usability: Gathering qualitative feedback through a questionnaire to evaluate the user's workload during the tasks.

## Performances:

- Insertion procedure accuracy: 
  - Translation error from the target (median ± std.) -> 3.2 ± 1.4 mm 
  - Orientation error with respect to the pre-planned path (median ± std.) ->  1.2 ± 0.9° 
- Usability: The qualitative feedback gathered through the user questionnaire shown that the proposed system (AA) had the *__highest__* usability compared to all the other setups, including the setup emulating the operating room (SM).

## Repository Structure
- src/: Contains the unity project to be uploaded in the Hololens2 and the ROS catkin_ws for the robot control.
- images/: Contains the images of the repository.
- docs/: Contains the user manual for the system and a more detailed explaination of the robot control strategy.
- videos/: Includes demo videos showcasing the system in action.


