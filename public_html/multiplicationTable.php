<?php
$size = 6;

if($size > 0) {
    echo "<h2>Multiplication Table for $size</h2>";
    echo "<table border='1'>";
    for ($i = 0; $i <= $size; $i++) {
        echo "<tr>";
        for ($j = 0; $j <= $size; $j++) {
            $result = $i * $j;
            if ($i == 0 && $j == 0) {
                echo "<td></td>";
            } elseif ($i == 0) {
                echo "<td><b>$j</b></td>";
            } elseif ($j == 0) {
                echo "<td><b>$i</b></td>";
            } else {
                echo "<td>$result</td>";
            }
        }
        echo "</tr>";
    }
    echo "</table>";
} else {
    echo "<p>Enter a valid integer.</p>";
}

?>
}