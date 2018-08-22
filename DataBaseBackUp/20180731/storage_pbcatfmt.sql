-- MySQL dump 10.13  Distrib 8.0.12, for Win64 (x86_64)
--
-- Host: 39.104.134.216    Database: storage
-- ------------------------------------------------------
-- Server version	8.0.11

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
-- Table structure for table `pbcatfmt`
--

DROP TABLE IF EXISTS `pbcatfmt`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `pbcatfmt` (
  `pbf_name` varchar(30) NOT NULL,
  `pbf_frmt` varchar(254) DEFAULT NULL,
  `pbf_type` smallint(6) DEFAULT NULL,
  `pbf_cntr` int(11) DEFAULT NULL,
  UNIQUE KEY `pbcatf_x` (`pbf_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pbcatfmt`
--

LOCK TABLES `pbcatfmt` WRITE;
/*!40000 ALTER TABLE `pbcatfmt` DISABLE KEYS */;
INSERT INTO `pbcatfmt` VALUES ('[General]','[General]',81,0),('#,##0','#,##0',81,0),('#,##0.00','#,##0.00',81,0),('$#,##0;($#,##0)','$#,##0;($#,##0)',81,0),('$#,##0;[RED]($#,##0)','$#,##0;[RED]($#,##0)',81,0),('$#,##0.00;($#,##0.00)','$#,##0.00;($#,##0.00)',81,0),('$#,##0.00;[RED]($#,##0.00)','$#,##0.00;[RED]($#,##0.00)',81,0),('0','0',81,0),('0.00','0.00',81,0),('0.00%','0.00%',81,0),('0.00E+00','0.00E+00',81,0),('0%','0%',81,0),('d-mmm','d-mmm',84,0),('d-mmm-yy','d-mmm-yy',84,0),('h:mm AM/PM','h:mm AM/PM',84,0),('h:mm:ss','h:mm:ss',84,0),('h:mm:ss AM/PM','h:mm:ss AM/PM',84,0),('m/d/yy','m/d/yy',84,0),('m/d/yy h:mm','m/d/yy h:mm',84,0),('mmm-yy','mmm-yy',84,0);
/*!40000 ALTER TABLE `pbcatfmt` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-07-31 19:50:06
