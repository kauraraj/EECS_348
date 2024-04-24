<?php
$size = $_POST["size"];

if($size > 0) {
    echo "<h2>Multiplication Table for $size</h2>";
    echo "<table border='1'>";
    for ($i = 0; $i <= $size; $i++) {
        echo "<tr>";
        for ($j = 0; $j <= $size; $j++) {
            if ($i == 0 && $j == 0) {
                echo "<td></td>";
            } elseif ($i == 0) {
                echo "<td><b>$j</b></td>";
            } elseif ($j == 0) {
                echo "<td><b>$i</b></td>";
            } else {
                $result = $i * $j;
                echo "<td>$result</td>";
            }
        }
        echo "</tr>";
    }
    echo "</table>";
} else {
    echo "<p>Enter a valid integer.</p>";
}