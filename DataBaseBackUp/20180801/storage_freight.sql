-- MySQL dump 10.13  Distrib 8.0.12, for Win64 (x86_64)
--
-- Host: 47.254.76.209    Database: storage
-- ------------------------------------------------------
-- Server version	8.0.12

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `freight`
--

DROP TABLE IF EXISTS `freight`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `freight` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tracking_id` varchar(255) DEFAULT NULL,
  `Carrier_id` varchar(255) DEFAULT NULL,
  `est_city` varchar(255) DEFAULT NULL,
  `est_country` varchar(255) DEFAULT NULL,
  `arr_city` varchar(255) DEFAULT NULL,
  `arr_country` varchar(255) DEFAULT NULL,
  `est_date` datetime DEFAULT NULL,
  `arr_date` datetime DEFAULT NULL,
  `delayed` int(11) DEFAULT NULL,
  `Customs` int(11) DEFAULT NULL,
  `customs_name` varchar(255) DEFAULT NULL,
  `Customs_city` varchar(255) DEFAULT NULL,
  `Custom_check_id` varchar(255) DEFAULT NULL,
  `custom_pass` int(11) DEFAULT NULL,
  `Imm_city` varchar(255) DEFAULT NULL,
  `Imm_Add` varchar(255) DEFAULT NULL,
  `Imm_Country` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `freight`
--

LOCK TABLES `freight` WRITE;
/*!40000 ALTER TABLE `freight` DISABLE KEYS */;
/*!40000 ALTER TABLE `freight` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-08-02  3:24:34
