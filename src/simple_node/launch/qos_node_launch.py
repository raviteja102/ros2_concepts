from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    config = os.path.join(
        get_package_share_directory("simple_node"), "config", "params.yaml"
    )
    return LaunchDescription(
        [
            Node(
                package="simple_node",
                executable="qos_node",
                name="qos_node",
                output="screen",
                parameters=[config],
            )
        ]
    )
