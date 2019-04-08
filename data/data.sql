--
-- Entity101 DataSet for mysql
--
DROP DATABASE IF EXISTS `entity101`;
CREATE DATABASE IF NOT EXISTS `entity101` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `entity101`;



-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE `users` (
  `userID` int(50) DEFAULT NOT NULL PRIMARY KEY,
  `username` varchar(50) DEFAULT NULL,
  `password` varchar(50) DEFAULT NULL);

insert into users (username, password) values ('entity101','entity101');

CREATE TABLE `activeNeurons` (
  `neuronID` int(50) DEFAULT NOT NULL PRIMARY KEY,
  `numberOfNeurons` int(10000) DEFAULT NOT NULL,
  `numberOfLayers` int(10000) DEFAULT NOT NULL,
  `numberOfInputNeurons` int(10000) DEFAULT NOT NULL,
  `numberOfOutputNeurons` int(10000) DEFAULT NOT NULL,
  `comment` varchar(100) DEFAULT NULL);

insert into activeNeurons (neuronID, numberOfLayers, numberOfInputNeurons, numberOfOutputNeurons,comment) values (1,1,1,1,'exampleData');
